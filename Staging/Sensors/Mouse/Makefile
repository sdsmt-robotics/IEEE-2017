READ_SRC = read.cpp FileHandler.cpp
READ_OBJ = $(READ_SRC:.cpp=.o)

WRITE_SRC = write.cpp FileHandler.cpp mouse.cpp
WRITE_OBJ = $(WRITE_SRC:.cpp=.o)

CC = g++
LINK = g++

CFLAGS = -O3 -Wall -Wextra -Wpedantic -std=c++11
CXXFLAGS = $(CFLAGS)

READ_TARGET = read
WRITE_TARGET = write

all: $(READ_TARGET)
all: $(WRITE_TARGET)

$(WRITE_TARGET): $(WRITE_OBJ)
	$(LINK) -o $@ $^ $(CFLAGS)

$(READ_TARGET): $(READ_OBJ)
	$(LINK) -o $@ $^ $(CFLAGS)

.cpp:
	$(CC) -o $@ $@.cpp

clean:
	rm -rf *.o *.gch *.orig $(READ_TARGET) $(WRITE_TARGET)

format:
	astyle --indent=spaces --style=allman *.h *.cpp
