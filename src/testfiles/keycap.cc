//g++ -I /usr/include/libevdev-1.0 -levdev keycapture.cc -o keycap.cc
#include <fcntl.h>
#include <unistd.h>
#include <libevdev/libevdev.h>

#include <iostream>
using namespace std;;

int main() {

    char* device = "/dev/input/event22";
    int fd = open(device, O_RDONLY);

    libevdev* dev;
    if(libevdev_new_from_fd(fd, &dev) != 0) {
        cerr << "Error creating libevdev device" << endl;
        return 69;
    }
    
    if(libevdev_grab(dev, LIBEVDEV_GRAB) != 0) {
        cerr << "Grab failed" << endl;
        return 69;
    }

    for(int i = 0; i < 100; i++) {
        input_event input;
        int rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &input);

        while (rc == LIBEVDEV_READ_STATUS_SYNC)
            rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_SYNC, &input);

        if(rc == -EAGAIN) continue;

        cout << "Event Detected" << endl;
        cout << "Event Type: " << input.type << endl;
        cout << "Event Code: " << input.code << endl;
        cout << "Event Value: " << input.value << endl;
        cout << endl;
    }


    libevdev_grab(dev, LIBEVDEV_UNGRAB);
    libevdev_free(dev);
    close(fd);

    return 0;
}