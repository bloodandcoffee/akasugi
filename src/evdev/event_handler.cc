#include <iostream>
#include <errno.h>

#include "event_handler.h"
using namespace std;

EventHandler::InputDevice EventHandler::id;
EventHandler::OutputDevice EventHandler::od;
bool EventHandler::isCapturing;
EventHandler::DeviceState EventHandler::status;

void EventHandler::init() {

    id = EventHandler::InputDevice("/dev/input/event4");

    if(id.status != OK) {

        status = id.status;
        return;

    }


    od = EventHandler::OutputDevice(id.readSupportedEvents());

    if(od.status != OK) {

        status = od.status;
        return;

    }

    status = OK;
    startCapture();
}

void EventHandler::startCapture() {
    
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

void EventHandler::stopCapture() {

    isCapturing = false;
    id.setGrab(false);

}