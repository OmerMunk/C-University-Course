/*
 Created by Omer Munk
*/

/* 
	This is the main program of the scalar product exercise.
	This program calls another programm namd scalar_priduct_module, which is the informative and the calculative program.
	The program scalar_product_module, printt some informative instructions for the user and/or for the outputfile,
	and calculates the scalar product of two vectors, using an algecric method.
	More details and further explanations can be found in the scalar product module.
 */


#include <stdio.h>
#include "header.h"


int main() {
	printf("\nExecuting the Scalar Product exercise: \n");
	
	/* Calling the main driver method of the scalar product module */
    scalar_product_driver();
    
    
    printf("\nFinished execution for the Scalar Product exercise \n");
    return 0;
}

