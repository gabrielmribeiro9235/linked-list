CC = gcc
CFLAGS = -Wall -Wextra

all = my_program

my_program: main.o linked_list.o
	  $(CC) $(CFLAGS) -o my_program main.o linked_list.o

main.o: main.c linked_list.h
	  $(CC) $(CFLAGS) -c -o main.o main.c

linked_list.o: linked_list.c linked_list.h
	  $(CC) $(CFLAGS) -c -o linked_list.o linked_list.c

clean:
	  rm -f my_program main.o linked_list.o