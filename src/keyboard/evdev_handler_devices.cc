#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "evdev_handler.h"
using namespace std;

EventInterceptor::InputDevice::InputDevice() {

    status = ID_STATUS_UNITIALIZED;

}

EventInterceptor::InputDevice::InputDevice(char* path) {

    fd = open(path, O_RDONLY);
    if(fd < 0) {
        status = ID_STATUS_PATH_DNE;
        return;
    }

    if(libevdev_new_from_fd(fd, &dev) != 0) {
        status = ID_STATUS_EVDEV_CREATE_FAILED;
        return;
    }

    status = ID_STATUS_OK;

}

EventInterceptor::InputDevice::~InputDevice() {

    if(status == ID_STATUS_UNITIALIZED) return;
    if(status == ID_STATUS_EVDEV_CREATE_FAILED) return;

    if(status -= ID_STATUS_GRABBED) libevdev_grab(dev, LIBEVDEV_UNGRAB);
    libevdev_free(dev);

    close(fd);

}

void EventInterceptor::InputDevice::setGrab(bool c) {

    if(status == ID_STATUS_UNITIALIZED) return;
    if(status == ID_STATUS_EVDEV_CREATE_FAILED) return;

    if(libevdev_grab(dev, (c ? LIBEVDEV_GRAB : LIBEVDEV_UNGRAB))) {
        status = ID_STATUS_EVDEV_GRAB_FAILED;
    }

    status = c ? ID_STATUS_GRABBED : ID_STATUS_OK;

}

int EventInterceptor::InputDevice::readEvent(struct input_event& e) {

    if(status == ID_STATUS_UNITIALIZED) return -EINVAL;
    if(status == ID_STATUS_EVDEV_CREATE_FAILED) return -EINVAL;

    int rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &e);

    while (rc == LIBEVDEV_READ_STATUS_SYNC) {
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_SYNC, &e);
    }

    return rc;

}

EventInterceptor::DeviceSupportedEvents EventInterceptor::InputDevice::readSupportedEvents() {

    EventInterceptor::DeviceSupportedEvents supportedEvents;

    if(status == ID_STATUS_UNITIALIZED) return supportedEvents;
    if(status == ID_STATUS_EVDEV_CREATE_FAILED) return supportedEvents;

    for(int evType = 0; evType < EV_MAX; evType++) {

        int typeMax = libevdev_event_type_get_max(evType);
        if(typeMax < 0) continue;

        vector<EventCode> codes;

        for(int evCode = 0; evCode < typeMax; evCode++) {
            if(!libevdev_has_event_code(dev, evType, evCode)) continue;
            if(!libevdev_event_code_get_name(evType, evCode)) continue;

            EventCode ec;
            ec.type = evType;
            ec.code = evCode;

            if(evType == EV_ABS) {
                ec.absInfo = *libevdev_get_abs_info(dev, evCode);
            }

            if(evType == EV_REP) {
                ec.evRepVal = libevdev_get_event_value(dev, evType, evCode);
            }

            codes.push_back(ec);
        }

        if(!codes.empty()) {
            supportedEvents.types.push_back(evType);
            supportedEvents.codes.push_back(codes);
        }
    }

    supportedEvents.initialized = true;

    return supportedEvents;

}

EventInterceptor::OutputDevice::OutputDevice() {

    status = ID_STATUS_UNITIALIZED;
    
}

EventInterceptor::OutputDevice::OutputDevice(EventInterceptor::DeviceSupportedEvents supportedEvents) {

    if(!supportedEvents.initialized) {
        status = OD_STATUS_UNITIALIZED;
        return;
    }

    dev = libevdev_new();

    libevdev_set_name(dev, "Karatsuba Labs Co., Ltd. Akasugi Virtual Keyboard");
    libevdev_set_id_vendor(dev, 0x6969);
    libevdev_set_id_product(dev, 0x510D);
    libevdev_set_id_bustype(dev, BUS_VIRTUAL);

    bool setEventErr = false;

    for(int i = 0; i < supportedEvents.types.size(); i++) {
        int evType = supportedEvents.types.at(i);
        setEventErr = setEventErr || libevdev_enable_event_type(dev, evType);

        for(vector<EventCode>::iterator evCode = supportedEvents.codes.at(i).begin(); evCode < supportedEvents.codes.at(i).end(); evCode++) {
            if(evType == EV_ABS) {
                setEventErr = setEventErr || libevdev_enable_event_code(dev, evType, evCode->code, &evCode->absInfo);
            }
            else if(evType == EV_REP) {
                setEventErr = setEventErr || libevdev_enable_event_code(dev, evType, evCode->code, &evCode->evRepVal);
            }
            else setEventErr = setEventErr || libevdev_enable_event_code(dev, evType, evCode->code, NULL);
        }
    }

    if(setEventErr) {
        status = OD_STATUS_EVDEV_SET_EVENTS_FAILED;
        return;
    }

    if(libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev)) {
        status = OD_STATUS_UINPUT_CREATE_FAILED;
        return;
    }

    status = OD_STATUS_OK;

}

EventInterceptor::OutputDevice::~OutputDevice() {

    if(status == OD_STATUS_UNITIALIZED) return;
    if(status == OD_STATUS_UINPUT_CREATE_FAILED) return;

    libevdev_uinput_destroy(uidev);
    libevdev_free(dev);

}

void EventInterceptor::OutputDevice::sendEvent(struct input_event e) {

    if(status == OD_STATUS_UNITIALIZED) return;
    if(status == OD_STATUS_UINPUT_CREATE_FAILED) return;

    libevdev_uinput_write_event(uidev, e.type, e.code, e.value);

}