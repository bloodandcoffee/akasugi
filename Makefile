CXX=g++
CXXFLAGS=-std=c++20 -Wall -MMD -O2 -mtune=native -I /usr/include/libevdev-1.0 -levdev
EXEC=bin/akasugi
OBJECTS=src/main.o src/akasugi/akasugi.o src/romaji_parser/romaji_parser.o src/evdev/event_handler.o src/evdev/devices.o
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
