scalar_product: main.o scalar_product_module.o
	gcc -Wall -ansi -pedantic main.o scalar_product_module.o -o scalar_product

main.o: main.c header.h
	gcc -c -Wall -ansi -pedantic main.c -o main.o
scalar_product_module.o: scalar_product_module.c header.h
	gcc -c -Wall -ansi -pedantic scalar_product_module.c -o scalar_product_module.o
