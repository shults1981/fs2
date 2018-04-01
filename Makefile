TARGET=fs2
CC=g++
PREFIX=/usr/local/bin



all:$(TARGET)

$(TARGET):fs2.o game.o unit.o
	$(CC) -g -o $(TARGET) fs2.o game.o unit.o -lncurses
fs2.o:funny_snake2.cpp
	$(CC) -g -c -o fs2.o funny_snake2.cpp
game.o:game.cpp game.h
	$(CC) -g -c -o game.o game.cpp
unit.o:unit.cpp unit.h
	$(CC) -g -c -o unit.o unit.cpp

clean:
	rm -rf  $(TARGET) *.o

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)