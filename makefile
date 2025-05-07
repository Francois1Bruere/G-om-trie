CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
<<<<<<< HEAD
LDFLAGS = -lX11
=======
LDFLAGS = -lgdi32 -luser32
>>>>>>> 09649898c36814cafc288fc18f0c18847106a5a7
SRC = src/*.cpp src/shapes/*.cpp main.cpp

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)

clean:
	rm -f main