#include <iostream>
#include <algorithm>
#include <errno.h>

#include "event_handler.h"
#include "../akasugi/akasugi.h"
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

    input_event e;
    while(isCapturing) {

        // Do nothing if there are no input events
        if(id.readEvent(e) == -EAGAIN) continue;

        // Process key events only
        else if(e.type == EV_KEY) {
            
            // Pass toggle control sequence mode for control, alt, and super keys
            if(find(&modifierKeys, &modifierKeys + 6, e.code) != (&modifierKeys + 6)) akasugi.setModifierIsPressed(e.value);

            // Pass through all key events when modifier keys are pressed
            else if(akasugi.getModifierIsPressed()) else od.sendEvent(e);

            // Ignore keyup events
            else if(e.value == 0) continue;

            // Use Caps Lock to toggle between JP and EN
            // Toggle Japanese Mode for single press, pass through event for autorepeat events
            else if(e.code == KEY_CAPSLOCK) {

                // Toggle JP mode on Caps Lock press
                if(e.value == 1) akasugi.toggleEnglishMode();
                // Ignore/pass through all other caps lock events
                else od.sendEvent(e);

            }

            // Send latin alphabet and punctuation events to JP keyboard
            else if(akasugi.accepts(e.code)){

                akasugi.onGetKeyboardInput(e.code);

            }

            // Pass through everything else
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