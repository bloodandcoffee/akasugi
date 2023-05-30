#include <algorithm>
#include <iostream>

#include "akasugi.h"
#include "../romaji_parser/romaji_parser.h"
using namespace std;


bool Akasugi::isJapaneseMode;
bool Akasugi::isModPressed;
bool Akasugi::isShiftPressed;

void Akasugi::init() {

    isJapaneseMode = true;
    isModPressed = false;
    isShiftPressed = false;

}

// Returns true if key is consumed, false if key should be passed through
bool Akasugi::onGetKeyboardInput(int code, int value) {

    // Check if a modifier key is being pressed, or if JP mode is off
    if(isModPressed || isJapaneseMode == false) return false;

    // Pass through control, alt, and super keys
    if(find(modifierKeys, (modifierKeys + 6), code) != (modifierKeys + 6)) {
        
        isModPressed = value;
        return false;

    }

    // Pass through shift key presses
    if(code == KEY_LEFTSHIFT || code == KEY_RIGHTSHIFT) {

        isShiftPressed = value;
        return false;

    }

    // Ignore keyup events
    if(value == 0) return false;

    // Use Caps Lock to toggle between JP and EN
    // Toggle Japanese Mode for single press, pass through event for autorepeat events
    if(code == KEY_CAPSLOCK && value == 1) {

        // Toggle JP mode on Caps Lock press
        isJapaneseMode = !isJapaneseMode;;
        return true;

    }

    // TODO: PROPERLY OUTPUT SYMBOLS INSTEAD OF PRINTING TO STDOUT

    // Output japanese punctuations
    // More JP punctuations may be added later. For now, this keyboard is meant to be convenient for gaijins
    if(code == KEY_4 && isShiftPressed) {

        sendSymbol("¥");
        return true;

    } else if(code == KEY_DOT) {

        sendSymbol("。");
        return true;

    } else if(code == KEY_COMMA) {

        sendSymbol("、");
        return true;

    }

    // Consume and process romaji key inputs
    if((code >= KEY_Q && code <= KEY_P) ||
        (code >= KEY_A && code <= KEY_L) ||
        (code >= KEY_Z && code <= KEY_M)) {

        consumeKeyboardInput(code);
        return true;

    }
    

    return false;

}


// Convert keycodes to lowercase ASCII
char Akasugi::getAscii(int code) {

    if(!keyMap.contains(code)) return 0;
    else return keyMap.at(code);

}

// Send a unicode symbol to output
void Akasugi::sendSymbol(string symbol) {

    // Should actually send it to output instead of terminal
    // This is just for temporary debugging
    cout << symbol;

}

// Sends the romaji to the DFA - this expects a valid ASCII character
void Akasugi::consumeKeyboardInput(int keycode) {
    
    char ascii = getAscii(keycode);

    if(ascii == 0) return;
    else RomajiParser::consumeChar(ascii);

    // After sending input, check if a valid kana is available for output
    if(RomajiParser::isLeaf()) {
        
        sendSymbol(RomajiParser::getValue()->hiragana);
        RomajiParser::reset();

    }

}