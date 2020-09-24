CFLAGS=-ansi -O2 -fstack-protector-strong -std=c99 -Wall -Wextra -pedantic
RMFLAGS=-f

CC=gcc
RM=rm

.PHONY: clean

quish:
	$(CC) $(CFLAGS) -c main.c -o quish

install: quish
	$(INSTALL) quish /usr/local/bin/

clean:
	$(RM) $(RMFLAGS) quish