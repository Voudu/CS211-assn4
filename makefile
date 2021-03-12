out: proj4base.o stack.o tree.o
	gcc -o stack tree proj4base.o stack.o tree.o

proj4base.o: proj4base.c tree.h stack.h
	gcc -c proj4base.c

stack.o: stack.c stack.h
	gcc -c stack.c

tree.o: tree.c tree.h
	gcc -c tree.c

clean:
	rm proj4base.o stack.o stack tree.o tree