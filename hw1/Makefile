all: detab reverse fsm

detab: detab.c
	gcc -o detab detab.c

reverse: reverse.c
	gcc -o reverse reverse.c

fsm: main.c fsm.c fsm.h
	gcc -c main.c fsm.c
	gcc -o fsm main.o fsm.o

clean:
	rm -f detab reverse fsm *.o
