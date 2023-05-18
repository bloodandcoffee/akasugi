#ifndef AKASUGI_H
#define AKASUGI_H


class akasugi {

    public:

    static void toggleJapaneseMode();
    static void setModifierIsPressed(bool state);
    static bool getModifierIsPressed();

    static bool accepts(int keypress);
    static void onGetKeyboardInput(int keypress);

};

#endif