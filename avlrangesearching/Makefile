CXX = g++
CXXFLAGS = -Wall -std=c++17

all: wordrange

wordrange: main.o wordrange.o
	$(CXX) $(CXXFLAGS) -o wordrange main.o wordrange.o

main.o: main.cpp wordrange.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

wordrange.o: wordrange.cpp wordrange.hpp
	$(CXX) $(CXXFLAGS) -c wordrange.cpp

clean:
	rm -f *.o wordrange
