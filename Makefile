CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = biquadris
SOURCES = $(wildcard *.cc)   # Pick up all implementation files
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
