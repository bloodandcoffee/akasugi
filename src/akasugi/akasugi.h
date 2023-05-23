#ifndef AKASUGI_H
#define AKASUGI_H

#include <string>
#include <map>
#include <linux/input-event-codes.h>

// List of Modifier Keys
const int modifierKeys[] = {KEY_LEFTCTRL, KEY_LEFTALT, KEY_LEFTMETA, KEY_RIGHTALT, KEY_RIGHTCTRL, KEY_RIGHTMETA};

const std::map<int, char> keyMap = {

    {KEY_Q, 'q'}, {KEY_W, 'w'}, {KEY_E, 'e'}, {KEY_R, 'r'}, {KEY_T, 't'}, {KEY_Y, 'y'}, {KEY_U, 'u'}, {KEY_I, 'i'}, {KEY_O, 'o'}, {KEY_P, 'p'},
    {KEY_A, 'a'}, {KEY_S, 's'}, {KEY_D, 'd'}, {KEY_F, 'f'}, {KEY_G, 'g'}, {KEY_H, 'h'}, {KEY_J, 'j'}, {KEY_K, 'k'}, {KEY_L, 'l'},
    {KEY_Z, 'z'}, {KEY_X, 'x'}, {KEY_C, 'c'}, {KEY_V, 'v'}, {KEY_B, 'b'}, {KEY_N, 'n'}, {KEY_M, 'm'}

};

class Akasugi {

    static bool isJapaneseMode;
    static bool isModPressed;
    static bool isShiftPressed;

    static void consumeKeyboardInput(int keycode);
    static void sendSymbol(std::string symbol);
    static char getAscii(int code);


    public:

    static void init();
    static bool onGetKeyboardInput(int code, int value);

};

#endif