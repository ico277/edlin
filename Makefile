PREFIX = /usr/local
CC = cc
CFILES = $(wildcard src/*.c)
EXECUTABLE = edlin
CFLAGS = -Wall -Wextra -O2

build:
	$(CC) $(CFILES) -o $(EXECUTABLE).out $(CFLAGS)

install: ./$(EXECUTABLE)
	cp ./$(EXECUTABLE).out $(PREFIX)/bin/$(EXECUTABLE)

uninstall: $(PREFIX)/bin/$(EXECUTABLE)
	rm $(PREFIX)/bin/$(EXECUTABLE)

clean:
	rm ./*.out ./*.o 2> /dev/null || true
	rm ./vgcore* 2> /dev/null || true

run: build
	./$(EXECUTABLE).out

debug: clean
	$(CC) $(CFILES) -g -o $(EXECUTABLE)_debug.out $(CFLAGS)
	gdb $(EXECUTABLE)_debug.out
