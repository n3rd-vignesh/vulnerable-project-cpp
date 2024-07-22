# Makefile for compiling main_server.cpp and pencil_box.cpp securely

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

all: main_server pencil_box

main_server: main_server.o
	$(CXX) $(CXXFLAGS) -o main_server main_server.o

main_server.o: main_server.cpp
	$(CXX) $(CXXFLAGS) -c main_server.cpp

pencil_box: pencil_box.o
	$(CXX) $(CXXFLAGS) -o pencil_box pencil_box.o

pencil_box.o: pencil_box.cpp
	$(CXX) $(CXXFLAGS) -c pencil_box.cpp

clean:
	rm -f main_server pencil_box *.o
