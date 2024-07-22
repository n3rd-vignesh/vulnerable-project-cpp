# Makefile for main_server.cpp and pencil_box.cpp

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Targets
all: main_server pencil_box

# Compile main_server.cpp
main_server: main_server.o
	$(CXX) $(CXXFLAGS) -o main_server main_server.o

main_server.o: main_server.cpp
	$(CXX) $(CXXFLAGS) -c main_server.cpp

# Compile pencil_box.cpp
pencil_box: pencil_box.o
	$(CXX) $(CXXFLAGS) -o pencil_box pencil_box.o

pencil_box.o: pencil_box.cpp
	$(CXX) $(CXXFLAGS) -c pencil_box.cpp

# Clean command
clean:
	rm -f main_server pencil_box *.o
