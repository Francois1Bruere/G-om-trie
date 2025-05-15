CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
LDFLAGS = -lX11  # ← ou bien -lgdi32 -luser32, selon ton OS
SRC = src/*.cpp src/shapes/*.cpp main.cpp

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)

clean:
	rm -f main
