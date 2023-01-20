#include <errno.h>

#include "evdev_handler.h"
using namespace std;

EventInterceptor::InputDevice EventInterceptor::id;
EventInterceptor::OutputDevice EventInterceptor::od;

void EventInterceptor::init() {

    id = EventInterceptor::InputDevice("/dev/input/event4");
    od = EventInterceptor::OutputDevice(id.readSupportedEvents());
    startCapture();

}

void EventInterceptor::startCapture() {
    isCapturing = true;

    id.setGrab(true);

    while(isCapturing) {

        input_event e;
        if(id.readEvent(e) == -EAGAIN) continue;

        od.sendEvent(e);

    }

    id.setGrab(false);

}

void EventInterceptor::stopCapture() {

    isCapturing = false;
    id.setGrab(false);

}