CXX=g++
CXXFLAGS=-std=c++20 -Wall -MMD
INCLUDEFLAGS=
EXEC=akasugi
OBJECTS=src/main.cc
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${INCLUDEFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
