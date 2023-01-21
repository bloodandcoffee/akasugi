#include <iostream>
#include <sstream>
#include <string>

#include "converter/kana_generator.h"
#include "keyboard/evdev_handler.h"

using namespace std;

int main() {

    EventInterceptor::init();
    EventInterceptor::startCapture();

    return 0;
}