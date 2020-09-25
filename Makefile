CFLAGS=-ansi -O2 -std=c99 -Wall -Wextra -pedantic
RMFLAGS=-f

CC=gcc
RM=rm

.PHONY: all clean

all: quish

quish: shell.c
	$(CC) $(CFLAGS) main.c -o quish

install: quish
	$(INSTALL) quish /usr/local/bin/

clean:
	$(RM) $(RMFLAGS) quish