//g++ -levdev keycapture.cc
#include <fcntl.h>
#include <unistd.h>
#include <libevdev-1.0/libevdev/libevdev.h>

#include <iostream>
using namespace std;;

int main() {

    char* device = "/dev/input/event4";
    int fd = open(device, O_RDONLY);

    struct libevdev* dev;
    libevdev_new_from_fd(fd, &dev);
    libevdev_grab(dev, LIBEVDEV_GRAB);

    for(int i = 0; i < 100; i++) {
        struct input_event input;
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