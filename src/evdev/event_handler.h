#ifndef EVDEV_HANDLER_H
#define EVDEV_HANDLER_H

#include <vector>
#include <linux/input.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>


// List of Modifier Keys
const int modifierKeys[] = {KEY_LEFTCTRL, KEY_LEFTALT, KEY_LEFTMETA, KEY_RIGHTALT, KEY_RIGHTCTRL, KEY_RIGHTMETA};

class EventHandler {

    public:
    enum DeviceState {
        OK,
        UNINITIALIZED,
        GRABBED,
        OPEN_DEVICE_FAILED,
        SET_EVENTS_FAILED,
        CREATE_DEVICE_FAILED,
        GRAB_FAILED
    };

    private:
    struct EventCode {
        int type;
        int code;
        input_absinfo absInfo;
        int evRepVal;
    };

    struct DeviceSupportedEvents {
        bool initialized = false;
        std::vector<int> types;
        std::vector<std::vector<EventCode>> codes;
    };

    class InputDevice {
        char* path;
        int fd;
        libevdev* dev;

        public:
        DeviceState status;

        InputDevice();
        InputDevice(char* path);
        ~InputDevice();

        void setGrab(bool c);

        int readEvent(struct input_event& e);
        DeviceSupportedEvents readSupportedEvents();
    };

    class OutputDevice {
        libevdev* dev;
        libevdev_uinput* uidev;


        public:
        DeviceState status;

        OutputDevice();
        OutputDevice(DeviceSupportedEvents supportedEvents);
        ~OutputDevice();

        void sendEvent(struct input_event e);
    };

    static InputDevice id;
    static OutputDevice od;

    static bool isCapturing;

    public:
    static DeviceState status;
    
    static void init();
    static void startCapture();
    static void stopCapture();

};

#endif