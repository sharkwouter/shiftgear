TARGET = shiftgear
OBJS = main.o game.o player.o sprite.o background.o constants.o

CFLAGS = -Wall -Wextra -pedantic -std=c11 -O2 $(pkg-config sdl2 --cflags)
CXXFLAGS = $(CFLAGS)
CC = gcc

INCLUDES=
LIBS=-lSDL2

all: $(TARGET)
	echo Created $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(INCLUDES) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDES) $(LIBS)

clean:
	rm $(OBJS) $(TARGET)
