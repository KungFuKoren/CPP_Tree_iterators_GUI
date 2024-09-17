# //kkorenn1@gmail.com

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main

SRCS = main.cpp complex.cpp
HEADERS = tree.hpp node.hpp complex.hpp

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

all: $(TARGET)
