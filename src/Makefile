CXX = g++
CXXFLAGS = -Wall
TARGET = main

all: $(TARGET)

$(TARGET): *.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)  

.PHONY: clean