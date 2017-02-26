SRC = RoboClaw.cpp test.cpp easy_serial.cpp
OBJ = $(SRC:.cpp=.o)

CC = g++
LINK = g++

CFLAGS = -O3 -std=c++11 -Wall -Wextra -Wpedantic
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
