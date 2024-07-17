# Makefile

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

all: main_server

main_server: main_server.o enhanced_functionality.o
	$(CXX) $(CXXFLAGS) -o main_server main_server.o enhanced_functionality.o

main_server.o: main_server.cpp
	$(CXX) $(CXXFLAGS) -c main_server.cpp

enhanced_functionality.o: enhanced_functionality.cpp
	$(CXX) $(CXXFLAGS) -c enhanced_functionality.cpp

clean:
	rm -f main_server main_server.o enhanced_functionality.o
