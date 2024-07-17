CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
TARGET = main_server

all: $(TARGET)

$(TARGET): main_server.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main_server.cpp

clean:
	rm -f $(TARGET)
