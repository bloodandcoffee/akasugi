#ifndef evdev_HANDLER_H
#define evdev_HANDLER_H

#include <vector>

#include <linux/input.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>

class EventInterceptor {

    struct EventCode {
        int type;
        int code;
        input_absinfo absInfo;
        int evRepVal;
    };

    struct DeviceSupportedEvents {
        std::vector<int> types;
        std::vector<std::vector<EventCode>> codes;
    };

    class InputDevice {
        char* path;
        int fd;
        libevdev* dev;

        #define ID_STATUS_OK 0
        #define ID_STATUS_PATH_DNE 1
        #define ID_STATUS_EVDEV_CREATE_FAILED 2
        #define ID_STATUS_EVDEV_GRAB_FAILED 3
        char status;

        public:
        InputDevice(char* path);
        ~InputDevice();

        int readEvent(struct input_event& e);
        DeviceSupportedEvents readSupportedEvents();
    };

    class OutputDevice {
        libevdev* dev;
        libevdev_uinput* uidev;

        #define OD_STATUS_OK 0
        #define OD_STATUS_EVDEV_SET_EVENTS_FAILED 1
        #define OD_STATUS_UINPUT_CREATE_FAILED 2
        char status;

        public:
        OutputDevice(DeviceSupportedEvents supportedEvents);
        ~OutputDevice();

        void sendEvent(struct input_event e);
    };

};

#endif