#ifndef AKASUGI_H
#define AKASUGI_H

#include <linux/input-event-codes.h>

// List of Modifier Keys
const int modifierKeys[] = {KEY_LEFTCTRL, KEY_LEFTALT, KEY_LEFTMETA, KEY_RIGHTALT, KEY_RIGHTCTRL, KEY_RIGHTMETA};

class Akasugi {

    static bool isJapaneseMode;
    static bool isModPressed;
    static bool isShiftPressed;

    static void consumeKeyboardInput(int keycode);
    static void sendSymbol(int symbol);


    public:

    static void init();
    static bool onGetKeyboardInput(int code, int value);

};

#endif