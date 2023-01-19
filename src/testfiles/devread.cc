//g++ -I /usr/include/libevdev-1.0 -levdev devread.cc -o devread.out
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include <libevdev/libevdev.h>
using namespace std;

int main() {

    char* device = "/dev/input/event4";
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
        int typeMax = libevdev_event_type_get_max(evType);

        if(typeMax < 0 || typeName == NULL) continue;
        
        cout << typeName << endl;

        for(int evCode = 0; evCode < typeMax; evCode++) {
            if(libevdev_has_event_code(dev, evType, evCode)) {
                const char* codeName = libevdev_event_code_get_name(evType, evCode);
                
                if(codeName == NULL) continue;
                cout << "\t" << codeName << endl;
            }
        }
    }

    libevdev_free(dev);
    close(fd);

    return 0;
}