#Makefile to make compolation easier to type out
#Benjamin McDonnough

CXX = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) database.txt

$(PROGRAM): Quiz.cpp printResult.cpp main.cpp
	$(CXX) $(OPTIONS) Quiz.cpp printResult.cpp main.cpp -o $(PROGRAM) 

clean:
	rm *.out