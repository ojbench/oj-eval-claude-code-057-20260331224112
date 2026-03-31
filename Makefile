CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall
TARGET = code
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
