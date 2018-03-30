TARGET=fs2
CC=gcc
PREFIX=/usr/local/bin



all:$(TARGET)

$(TARGET):fs2.o game.o unit.o
	$(CC) -g -o $(TARGET) fs2.o game.o unit.o -lncurses
fs2.o:funny_snake2.c
	$(CC) -g -c -o fs2.o funny_snake2.c
game.o:game.c game.h
	$(CC) -g -c -o game.o game.c
unit.o:unit.c unit.h
	$(CC) -g -c -o unit.o unit.c

clean:
	rm -rf  $(TARGET) *.o

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)