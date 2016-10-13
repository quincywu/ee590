all: stack

stack: stack.c stack_operation.c stack_operation.h
	gcc -c stack.c stack_operation.c
	gcc -o stack stack.o stack_operation.o

clean:
	rm -f detab reverse fsm *.o
