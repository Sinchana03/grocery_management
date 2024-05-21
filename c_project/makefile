CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o customer.o inventory.o login.o linkedlist.o
	$(CC) $(CFLAGS) -o output/main main.o customer.o inventory.o login.o linkedlist.o

main.o: main.c customer.h inventory.h login.h linkedlist.h
	$(CC) $(CFLAGS) -c main.c  

customer.o: customer.c customer.h
	$(CC) $(CFLAGS) -c customer.c

inventory.o: inventory.c inventory.h linkedlist.h
	$(CC) $(CFLAGS) -c inventory.c

login.o: login.c login.h
	$(CC) $(CFLAGS) -c login.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	rm -f *.o output/main

