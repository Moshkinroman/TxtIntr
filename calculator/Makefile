CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = calculator
SRC = calculator.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
