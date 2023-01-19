//g++ -I /usr/include/libevdev-1.0 -levdev devread.cc -o devread.out
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include <libevdev/libevdev.h>
using namespace std;

const char* event_types[] = {
    "EV_SYN",
    "EV_KEY",
    "EV_REL",
    "EV_ABS",
    "EV_MSC",
    "EV_SW",
    "EV_LED",
    "EV_SND",
    "EV_REP",
    "EV_FF",
    "EV_PWR",
    "EV_FF_STATUS"
};

int main() {

    char* device = "/dev/input/event3";
    int fd = open(device, O_RDONLY);

    libevdev* dev;
    if(libevdev_new_from_fd(fd, &dev) != 0) {
        cerr << "Error creating libevdev device" << endl;
        return 69;
    }

    cout << "Reading from device " << device << endl;
    cout << "Name: " << libevdev_get_name(dev) << endl;
    //cout << "UUID: " << libevdev_get_uniq(dev) << endl;
    cout << "Vendor ID: " << libevdev_get_id_vendor(dev) << endl;
    cout << "Device ID: " << libevdev_get_id_product(dev) << endl;
    cout << "Bus Type: " << libevdev_get_id_bustype(dev) << endl;
    cout << "Revision: " << libevdev_get_id_version(dev) << endl;

    cout << "Events: " << EV_MAX << endl;
    for(int evType = 0; evType < EV_MAX; evType++) {
        const char* typeName = libevdev_event_type_get_name(evType);
        if(typeName != NULL) cout << typeName << " " << libevdev_event_type_get_max(evType) << endl;
        else cout << evType << endl;
    }

    libevdev_free(dev);
    close(fd);

    return 0;
}