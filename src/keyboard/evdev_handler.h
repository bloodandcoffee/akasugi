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
        bool initialized = false;
        std::vector<int> types;
        std::vector<std::vector<EventCode>> codes;
    };

    class InputDevice {
        char* path;
        int fd;
        libevdev* dev;

        #define ID_STATUS_UNITIALIZED -1
        #define ID_STATUS_OK 0
        #define ID_STATUS_GRABBED 1
        #define ID_STATUS_PATH_DNE 2
        #define ID_STATUS_EVDEV_CREATE_FAILED 3
        #define ID_STATUS_EVDEV_GRAB_FAILED 4
        char status;

        public:
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

        #define OD_STATUS_UNITIALIZED -1
        #define OD_STATUS_OK 0
        #define OD_STATUS_EVDEV_SET_EVENTS_FAILED 1
        #define OD_STATUS_UINPUT_CREATE_FAILED 2
        char status;

        public:
        OutputDevice();
        OutputDevice(DeviceSupportedEvents supportedEvents);
        ~OutputDevice();

        void sendEvent(struct input_event e);
    };

    static InputDevice id;
    static OutputDevice od;

    static bool isCapturing;

    public:
    static void init();
    static void startCapture();
    static void stopCapture();

};

#endif