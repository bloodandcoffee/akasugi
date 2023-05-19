#include <algorithm>

#include "akasugi.h"
using namespace std;


void Akasugi::init() {

    isJapaneseMode = true;
    isModPressed = false;

}

// Returns true if key is consumed, false if key should be passed through
bool Akasugi::onGetKeyboardInput(int code, int value) {

    // Check if a modifier key is being pressed, or if JP mode is off
    if(isModPressed || isJapaneseMode == false) return false;

    // Pass toggle control sequence mode for control, alt, and super keys
    if(find(modifierKeys, (modifierKeys + 6), code) != (modifierKeys + 6)) {
        
        isModPressed = value;
        return false;

    }

    // Ignore keyup events
    if(value == 0) false;

    // Use Caps Lock to toggle between JP and EN
    // Toggle Japanese Mode for single press, pass through event for autorepeat events
    if(code == KEY_CAPSLOCK && value == 1) {

        // Toggle JP mode on Caps Lock press
        isJapaneseMode = !isJapaneseMode;;
        return true;

    }

    // TODO: Check if key is a romaji or punctuation
    

    return true;

}