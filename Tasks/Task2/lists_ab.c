/* Written By Omer Munk. */


/* Includes o libraries and files. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

/* a char pointer. */
char* array;


/* Declerations of the counters, long unsigned int because we count characters, so it will be only zero or positive,
and long because the input has no limit. */
long unsigned int count_total, count_alpha_numeric;

/* Declarations of variables. c - the character of the input and future print, row - the rows of output, i - iterator for the output printing. */
int c, row, i;


int main (){

    long unsigned int size = SIZE;
    count_total = 0;
    count_alpha_numeric = 0;
    
    /* Allocating initial, predefined size to the pointer */
    array = (char*) malloc(sizeof (char) * SIZE);
    
    printf("Please type as many characters as you want.\nWhen you finish, type ctrl+d (for windows) or cmd+d (for linux/mac).\nThis programm will print the characters in an organized way (constant amount of characters in each row), and it will tell you how many characters typed, and how many alpha numeric characters typed.");
    

    while((c=getchar()) != EOF){ /* while the input is not End Of fILE - keep getting inputs */
        if (count_total >= size-1){ /* If the script reached here , the allocation of memory is not enough, it is needed to allocate more. */ 
            size = size+QUARTER_SIZE; /* Increasing the size by a quarter of the initial memory size allocation. */
            array = (char*)realloc(array, size); /* Using realloc to allocate more memory to the current pointer. */
            }
          if (isalnum((int)c)) /* Using isalnum to count the alpha numeric characters. */
            count_alpha_numeric++;
        array[count_total] = c; /* Storing the value of the input in the memory (which in the range of the pointer) */
        count_total++;
        }   
    printf("\n");
    if (array!=NULL){
    	for(row = 0 ; row< (count_total/CHARS_IN_ROW)+1 ; row++){ /* Iterating the rows. */
    		for(i = CHARS_IN_ROW*row; (i <= CHARS_IN_ROW*(row+1)) && i < count_total  ; i++){ /* Printing the characters in each row */
    			putchar(*(array+i));
    		}
    		printf("\n");
    	}
    	
    	printf("The input had %lu alpha numeric characters, and total of %lu characters\n",count_alpha_numeric, count_total);
   
	}
	return 0;
}

