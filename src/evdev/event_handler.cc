#include <algorithm>
#include <errno.h>

#include "event_handler.h"
#include "../akasugi/akasugi.h"
using namespace std;


EventHandler::InputDevice EventHandler::id;
EventHandler::OutputDevice EventHandler::od;
EventHandler::DeviceState EventHandler::status;
bool EventHandler::isCapturing;

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

    input_event e;
    while(isCapturing) {

        // Do nothing if there are no input events
        if(id.readEvent(e) == -EAGAIN) continue;

        // Process key events only
        else if(e.type == EV_KEY) {
            
            // If key event is consumed, do nothing
            if(Akasugi::onGetKeyboardInput(e.code, e.value)) continue;
            
            // If key event is not consumed, pass through key event
            else od.sendEvent(e);

        }

        // Pass through all other (non-key) events
        else od.sendEvent(e);

    }

    id.setGrab(false);

}

void EventHandler::stopCapture() {

    isCapturing = false;
    id.setGrab(false);

}