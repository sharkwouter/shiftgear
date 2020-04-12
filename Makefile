TARGET = shiftgear
OBJS = main.o game.o player.o sprite.o background.o constants.o

CFLAGS = -Wall -Wextra -pedantic -std=c11 -O2 -D_REENTRANT
CXXFLAGS = $(CFLAGS)
CC = gcc

# Applying output of
# $ pkg-config --cflags sdl2
# and
# $ pkg-config --libs sdl2
# is probably better than this
INCLUDES=-I/usr/include/SDL2
LIBS=-lSDL2

all: $(TARGET)
	echo Created $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(INCLUDES) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDES) $(LIBS)

clean:
	rm $(OBJS) $(TARGET)
