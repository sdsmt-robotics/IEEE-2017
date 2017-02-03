SRC = Arduino.cpp Packet.cpp test.cpp ../Serial/Serial.cpp
OBJ = $(SRC:.cpp=.o)

CC = g++
LINK = g++

CFLAGS = -O3 -Wall -Wextra -Wpedantic -std=c++11
CXXFLAGS = $(CFLAGS)

TARGET = test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LINK) -o $@ $^ $(CFLAGS)

.cpp:
	$(CC) -o $@ $@.cpp

clean:
	rm -rf *.o *.gch *.orig $(TARGET)

format:
	astyle --indent=spaces --style=allman *.h *.cpp
