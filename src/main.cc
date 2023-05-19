#include "akasugi/akasugi.h"
#include "romaji_parser/romaji_parser.h"
#include "evdev/event_handler.h"

using namespace std;

int main() {

    Akasugi::init();
    EventHandler::init();
    EventHandler::startCapture();

    return 0;
}