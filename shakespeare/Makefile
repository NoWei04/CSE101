CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = bard.o linkedlist.o
TARGET = bard

all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

bard.o: bard.cpp linkedlist.h
	$(CXX) $(CXXFLAGS) -c bard.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CXX) $(CXXFLAGS) -c linkedlist.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)
	