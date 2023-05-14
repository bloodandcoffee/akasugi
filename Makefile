CXX=g++
CXXFLAGS=-std=c++20 -Wall -MMD -O2 -mtune=znver3 -I /usr/include/libevdev-1.0 -levdev
EXEC=bin/akasugi
OBJECTS=src/main.o src/converter/kana_generator.o src/keyboard/evdev_handler.o src/keyboard/evdev_handler_devices.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	mkdir -p bin
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

install: remove ${EXEC}
	sudo cp bin/akasugi ${PREFIX}/bin/akasugi

remove:
	sudo rm -rf ${PREFIX}/bin/akasugi

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
	rm -rf bin
