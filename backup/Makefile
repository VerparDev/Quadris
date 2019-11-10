CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = quadris
OBJECTS = main.o grid.o gamegrid.o nextblockgrid.o cell.o textdisplay.o graphicsdisplay.o block.o lblock.o jblock.o sblock.o zblock.o tblock.o iblock.o oblock.o badblock.o subject.o observer.o info.o coord.o level.o zero.o one.o two.o three.o four.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX}-5 ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

