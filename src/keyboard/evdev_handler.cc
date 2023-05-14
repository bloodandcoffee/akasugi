#include <iostream>
#include <errno.h>

#include "evdev_handler.h"
using namespace std;

EventInterceptor::InputDevice EventInterceptor::id;
EventInterceptor::OutputDevice EventInterceptor::od;
bool EventInterceptor::isCapturing;
EventInterceptor::DeviceState EventInterceptor::status;

void EventInterceptor::init() {

    id = EventInterceptor::InputDevice("/dev/input/event4");

    if(id.status != OK) {

        status = id.status;
        return;

    }


    od = EventInterceptor::OutputDevice(id.readSupportedEvents());

    if(od.status != OK) {

        status = od.status;
        return;

    }

    status = OK;
    startCapture();
}

void EventInterceptor::startCapture() {
    
    if(status != OK) return;

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