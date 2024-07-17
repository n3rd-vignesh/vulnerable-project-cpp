CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
TARGET1 = main_server
TARGET2 = enhanced_functionality

all: $(TARGET1) $(TARGET2)

$(TARGET1): main_server.cpp
	$(CC) $(CFLAGS) -o $(TARGET1) main_server.cpp

$(TARGET2): enhanced_functionality.cpp
	$(CC) $(CFLAGS) -o $(TARGET2) enhanced_functionality.cpp

clean:
	rm -f $(TARGET1) $(TARGET2)
