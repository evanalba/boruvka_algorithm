CXX  = g++
CXXFLAGS = --std=c++11 -Wall
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(TARGET).cpp
clean:
	$(RM) a.out
