/*
 Created by Omer Munk
*/

/* 
	This function is designed to get two numbers in decimal representation, and returns
	the amount of matching lighten bits between the two numbers, in a binary representation.
	The program is using the classic mathamatical way to convert the two numbers from decimal base to binary base.
	using the devision by 2 and then adding the remainder to a binary string from right to left.
	This is a mathematical way, using only math operators, no bitwise operations.
 */

#include <stdio.h>
#include "math.h"
#include "header.h"


/* Decleration of variables */
int result;
int sizeX;
int sizeY;
int min_range;
int remain;
int count;
int i;
int bitsX[MAX_SIZE];
int bitsY[MAX_SIZE];
ULI x;
ULI y;
ULI num;

/*
 An informative function that provides the user with instructions, gets an input and calls the calculation function.
 Assuming that the user will type positive integers , between 0 and 2 to the power 32.
 */
 
int main() {
    printf("Please enter two positive integer numbers\n");
    printf("The first number: \n");
    scanf("\n%lu", &x);
    printf("The second number: \n");
    scanf("\n%lu", &y);
    printf("The number of indexes that have matching \"lighten\" bits is:\n ");
    result = find_bits(x, y);
    printf("%d", result);
    return 0;
}

/* 
	This is the calculation funtion, it gets 2 integers from the driver function.
	first of all, it finds the size of bits needed to represent each number in binary base, using an array.
	Then, it does an iteration over the two arrays, and counting the  matching indexes that have the value '1'.
 */
 
int find_bits(ULI x, ULI y) {
    /* finding the size needed to x: */
    i = 1;
    sizeX = 2;
    while (pow(2, i) < x) {
        i++;
        if (pow(2, i) > x) {
            sizeX = i;
        }
    }

    /* finding the size needed to y: */
    i = 1;
    sizeY = 2;
    while (pow(2, i) < y) {
        i++;
        if (pow(2, i) > y) {
            sizeY = i;
        }
    }

    min_range = (sizeX > sizeY) ? sizeY : sizeX;


    /* converting x to bitsrepresenting binary base: */
    num = x;
    i = sizeX - 1;
    while (num != 0) {
        num = num / 2;
        remain = num % 2;
        bitsX[i] = remain;
        i--;
    }

    /* converting y to bits representing binary base: */
    num = y;
    i = sizeY - 1;
    while (num != 0) {
        num = num / 2;
        remain = num % 2;
        bitsY[i] = remain;
        i--;
    }

	/* Iterating every matching index, and count it if both arrays have a value of 1 */
    count = 0;
    for (i = min_range - 1; i >= 0; i--) {
        if (bitsX[i] == bitsY[i] && bitsX[i] == 1) {
            count++;
        }
    }
    return count;
}



