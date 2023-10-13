CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
DEBUG 		= -g3

all: main.c stack.o stack.h
	$(CC) $(CFLAGS) -o main main.c stack.o 

stack.o: stack.c stack.h
	$(CC) -c stack.c

clean:
	rm -f *o *exe