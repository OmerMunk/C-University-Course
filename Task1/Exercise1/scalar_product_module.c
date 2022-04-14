/*
 Created by Omer Munk
*/


/* 
	This module is an informative and calculative module for scalar product.
	The main purpose of this module is to get an input from a user, using the keyboard or a file,
	and calculate, according to the input, the scalar product of two vectors.
	It is assumed that the values of the two vectors are integers and the size
	(dimension) of the vecor is no more the 100
	
	There are informative insturctions functions, and a calculat function in this module.
	More details and further information about each function can be found at the begining of it.
 */


#include <stdio.h>
#include "header.h"


/* Variable declerations */
int size;
int result;
int i;
int vec1[MAX_SIZE];
int vec2[MAX_SIZE];


/* Definition of the scalar product driver function */

/* 
	This driver function is an informative function that call to the input instructions function, 
	according to the type of input chosen.
	It is assumed that the user will type 1 if the user want to type the values by using the keyboard.
	The user should not type 2 using the keyboard, it is meant to be an automatic input by a file.
	An appropriate input file should contain numbers by this order and meaning:
	2 x n... m...
	2 - choosing file input.
	x - the size (dimension) of the two vectors.
	n... - the values of the first vector, x of them.
	m... - the values of the second vector, x of them.
 */
 
int scalar_product_driver(){
	char choice;
	printf("\nEnter 1 for user typed inputs,\n2 for file input (automatically chosen if the program runs with an input file ),\nor any other key to exit \n");
	scanf("%c", &choice);
	if (choice == '1'){
		scalar_product_run_user_input();
		}
		
	/* This is automatically chosen when the programm runs with an input file from the terminal */
	else if (choice == '2'){ 
		scalar_product_run_file();
		}
	return 0;
}

/* This is the informative and the instructions function for a user-input running of the program */
int scalar_product_run_user_input(){
    printf("\nPlease enter a number, which will determine a size of 2 integer vectors, then enter the values of the vectors \n");
    printf("\nWhat is the size (dimension) of the vectors? Maximum size: 100 \n");
    
    /*
     	Decleration of size - a variable that holds the size (dimension) of the vectors,
     	and i - a variable that will be use as in index inside 'for' loops.  
     */
    scanf("%d", &size);
    
    for(i = 0 ; i < size ; i++){
        printf("\nPlease enter the %d value of the 1st vector \n", i+1);
        scanf("%d", &vec1[i]);
    }

    
    for(i = 0 ; i < size ; i++){
        printf("\nPlease enter the %d value of the 2st vector \n", i+1);
        scanf("%d", &vec2[i]);
    }

    printf("\nThe vectors you entered:\n");
    printf("\nVector 1: (");
    for(i = 0 ; i < size-1 ; i++){
        printf("%d ,", vec1[i]);
    }
    printf("%d)\n", vec1[size-1]);
   

    printf("\nVector 2: (");
    for(i = 0 ; i < size-1 ; i++){
        printf("%d ,", vec2[i]);
    }
    printf("%d)\n", vec2[size-1]);
   

    printf("\nThe scalar product of the two vectors is: \n");
    
    /* Calling the function that does the calculation of the scalar product*/
    result = scalar_product(size, vec1, vec2);
    printf("%d\n", result);
    return 0;
}

/* This is the informative and the instructions function for a file-input running of the program */
int scalar_product_run_file(){
    printf("\nPlease enter a number, which will determine a size (dimension) of 2 integer vectors, then enter the values of the vectors\n");
    printf("\nWhat is the size (dimension) of the vectors? \n");
    
    
    /*
     	Decleration of size - a variable that holds the size (dimension) of the vectors,
     	and i - a variable that will be use as in index inside 'for' loops.  
     */
    scanf("%d", &size);
    
    printf("\nPlease enter the %d values of the 1st vector\n", size);
    for(i = 0 ; i < size ; i++){
        scanf("%d", &vec1[i]);
        }
    
    printf("\nPlease enter the %d values of the 2st vector \n", size);
    for(i = 0 ; i < size ; i++){
        scanf("%d", &vec2[i]);
        }
    
    printf("\nThe vectors you entered: \n");
    printf("\nVector 1: (");
    for(i = 0 ; i < size-1 ; i++){
        printf("%d ,", vec1[i]);
    }
    printf("%d)\n", vec1[size-1]);

    printf("\nVector 2: (");
    for(i = 0 ; i < size-1 ; i++){
        printf("%d ,", vec2[i]);
    }
    printf("%d)\n", vec2[size-1]);
    

    printf("\nThe scalar product of the two vectors is: \n");
    
    /* Calling the function that does the calculation of the scalar product*/
    result = scalar_product(size, vec1, vec2);
    printf("%d\n", result);
    return 0;
}

/* Definition of the scalar product function */

/* 
	This function does the calculation of the scalar product of the two given vectors.
 */
int scalar_product(int n, int vec1[], int vec2[]){
    result = 0;
    
    /* Calculating the scalar product according to the algebric method to do it. */
    for(i = 0; i < n ; i++){
        result = result + vec1[i] * vec2[i];
    }
    return result;
}



