CXX = g++
CXXFLAGS = -Wall -std=c++17

all: nqueens

nqueens: main.cpp nqueens.cpp nqueens.hpp
	$(CXX) $(CXXFLAGS) -o nqueens main.cpp nqueens.cpp

clean:
	rm -f nqueens
	