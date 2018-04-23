TARGET=fs2
TARGET_TEST=fst2
CC=g++
PREFIX=/usr/local/bin



all:$(TARGET)
$(TARGET):funny_snake2.o game.o unit.o
	$(CC) -g -o $(TARGET) funny_snake2.o game.o unit.o -lncurses
funny_snake2.o:funny_snake2.cpp
	$(CC) -g -c -o funny_snake2.o funny_snake2.cpp
game.o:game.cpp game.h
	$(CC) -g -c -o game.o game.cpp
unit.o:unit.cpp unit.h
	$(CC) -g -c -o unit.o unit.cpp

test:$(TARGET_TEST)
$(TARGET_TEST):funny_snake2_test.o game.o unit.o
	$(CC) -g -o $(TARGET_TEST) funny_snake2_test.o game.o unit.o -lncurses
funny_snake2_test.o:funny_snake2_test.cpp
	$(CC) -g -c -o funny_snake2_test.o funny_snake2_test.cpp


clean:
	rm -rf  $(TARGET) *.o $(TARGET_TEST)

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)