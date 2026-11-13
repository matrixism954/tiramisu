CC = gcc
CFLAGS = -std=c11 -Wextra -Wpedantic -Wextra -O2

SRC = src/main.c src/service.c
OBJ = $(SRC:src/%.c=build/%.o)

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
DESTDIR = /usr/local

TARGET = build/tiramisu

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/tiramisu
	mkdir -p $(DESTDIR)/etc/tiramisu/services

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/tiramisu

clean:
	rm -rf build
