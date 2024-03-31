CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o customer.o inventory.o
    $(CC) $(CFLAGS) -o main main.o customer.o inventory.o

main.o: main.c customer.h inventory.h
    $(CC) $(CFLAGS) -c main.c

customer.o: customer.c customer.h
    $(CC) $(CFLAGS) -c customer.c

inventory.o: inventory.c inventory.h
    $(CC) $(CFLAGS) -c inventory.c

clean:
    rm -f *.o main
