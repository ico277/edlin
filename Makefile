PREFIX = /usr/local
CC = cc
CFILES = $(wildcard src/*.c)
EXECUTABLE = edlin
CFLAGS = -O2

build:
	$(CC) $(CFILES) -o $(EXECUTABLE) $(CFLAGS)

install: ./$(EXECUTABLE)
	cp ./$(EXECUTABLE) $(PREFIX)/bin/

uninstall: $(PREFIX)/bin/$(EXECUTABLE)
	rm $(PREFIX)/bin/$(EXECUTABLE)

clean:
	rm ./$(EXECUTABLE) 2> /dev/null || true
	rm ./$(EXECUTABLE)_debug 2> /dev/null || true
	rm ./vgcore* 2> /dev/null || true

run: build
	./$(EXECUTABLE)

debug: clean
	$(CC) $(CFILES) -o $(EXECUTABLE)_debug $(LDFLAGS) $(CFLAGS)
	gdb $(EXECUTABLE)_debug
