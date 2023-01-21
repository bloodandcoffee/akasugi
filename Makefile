CXX=g++
CXXFLAGS=-std=c++20 -Wall -MMD -O2 -mtune=znver3 -I /usr/include/libevdev-1.0 -levdev
EXEC=akasugi
OBJECTS=src/main.o src/converter/kana_generator.o src/keyboard/evdev_handler.o src/keyboard/evdev_handler_devices.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
