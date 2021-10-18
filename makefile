all: struct.o
	gcc -o list list.o
	
struct.o: list.c
	gcc -c list.c
	
run:
	./list

clean:
	rm *.o
	