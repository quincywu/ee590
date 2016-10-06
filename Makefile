all: fsm

fsm: main.c fsm.c fsm.h
		gcc -c main.c fsm.c
		gcc -o fsm main.o fsm.o

clean:
		rm -f fsm *.o
