CXX = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp -o $(PROGRAM) -std=c++11
	

clean:
	rm -f $(PROGRAM)
