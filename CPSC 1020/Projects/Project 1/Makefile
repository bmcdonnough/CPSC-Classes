#Program to determine the number of isolation days
#after being exposed to or testing positive for covid

#makefile to make compolaiton easier to type out
#Benjamin McDonnough

CXX = g++
OPTIONS = -Wall
PROGRAM = Date.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): Date.cpp calcDays.cpp main.cpp
	$(CXX) $(OPTIONS) Date.cpp calcDays.cpp main.cpp -o $(PROGRAM)

clean:
	rm *.out