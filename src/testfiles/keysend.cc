//g++ -I /usr/include/libevdev-1.0 -levdev keysend.cc -o keysend.out
#include <iostream>
#include <unistd.h>

#include <libevdev/libevdev-uinput.h>
using namespace std;

int main() {

    libevdev *dev = libevdev_new();
    
    libevdev_set_name(dev, "Karatsuba Labs Co., Ltd. Akasugi Virtual Keyboard");
    libevdev_set_uniq(dev, "2ac404ce-b02b-4911-a4ee-c37b77d45704");
    libevdev_set_id_vendor(dev, 0x6969);
    libevdev_set_id_product(dev, 0x510D);
    libevdev_set_id_bustype(dev, BUS_VIRTUAL);
    libevdev_set_id_version(dev, 0);


    libevdev_enable_event_type(dev, EV_KEY);
    libevdev_enable_event_code(dev, EV_KEY, KEY_F, NULL);

    libevdev_uinput *uidev;
    if(libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev) < 0) {
        cerr << "Error creating uinput device" << endl;
        return 69;
    }

    while(true) {
        libevdev_uinput_write_event(uidev, EV_KEY, KEY_F, 1);
        sleep(1);
        libevdev_uinput_write_event(uidev, EV_KEY, KEY_F, 0);
        sleep(1);
    }

    libevdev_uinput_destroy(uidev);
    libevdev_free(dev);

    return 0;
}