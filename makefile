out: proj4base.o tree.o stack.o
	gcc -o out proj4base.o tree.o stack.o

proj4base.o: proj4base.c stack.h tree.h
	gcc -c proj4base.c

tree.o: tree.c tree.h stack.h
	gcc -c tree.c

stack.o: stack.c stack.h tree.h
	gcc -c stack.c

clean:
	rm proj4base.o stack.o tree.o out