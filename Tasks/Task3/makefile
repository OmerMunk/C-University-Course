run: mainmat.o mymat.o
	gcc -Wall -ansi -pedantic mainmat.o mymat.o -o run
	
mainmat.o: mainmat.c mymat.h
	gcc -c -Wall -ansi -pedantic mainmat.c -o mainmat.o
	
mymat.o: mainmat.c mymat.h
	gcc -c -Wall -ansi -pedantic mymat.c -o mymat.o
