#include <iostream>
#include <sstream>
#include <string>

#include "romaji_parser/romaji_parser.h"
#include "evdev/event_handler.h"

using namespace std;

int main() {

    EventHandler::init();
    EventHandler::startCapture();

    return 0;
}