COMPILER = g++
OPTIONS = -Wall
PROGRAM = areaCalc.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): areaCalc.cpp Circle.cpp Rectangle.cpp Square.cpp Trapezoid.cpp
	$(CXX) $(OPTIONS) areaCalc.cpp Circle.cpp Rectangle.cpp Square.cpp Trapezoid.cpp -o $(PROGRAM)

clean:
	rm *.out