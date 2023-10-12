all: teststack.o stackcode.o
	gcc teststack.o stackcode.o -o stack

teststack.o: teststack.c
	gcc -c -Wall -pedantic -O2 teststack.c -o teststack.o

stackcode.o: 
	gcc -c -Wall -pedantic -O2 stackcode.c -o stackcode.o

clean:
	rm *.o