/* Written by Omer Munk */

/* Including the relevant libraries used for this program. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mymat.h"

/* Declarations of variables used for the program */

int i, j, k, c, choice, flag; /* i, j, and k are used for indexes, c for character input, choice for command choosing,
 * and flag for true/false. */
double scalar; /* for reading and scanning real-numbers */
double arguments_for_read_mat[SIZE * SIZE]; /* An array in order to store numbers for the 'read_mat' function */
int arguments_read;
char str_input[DOUBLE_MAXIMUM_DIGITS]; /* 'double' can hold 8 bytes, which is 64 bits, which is 2^64, that number has a maximum of 20 digits */
char *non_double_extract_from_str; /* this variable will hold a string if the input isn't a real number */
/* 3 matrix pointers */
mat *mat1Ptr;
mat *mat2Ptr;
mat *mat3Ptr;

/* matrix pointers array */
mat **matPtrArr[MAXIMUM_MATRICES_GIVEN_AS_PARAMETERS] = {&mat1Ptr, &mat2Ptr, &mat3Ptr};

/* An array for the matrices names */
char* matNames[MAT_AMOUNT];

/* An array for the command names */
char* commandNames[COMMAND_AMOUNT];

/* Chosen matrices names */
char *matChosenNames[MAXIMUM_MATRICES_GIVEN_AS_PARAMETERS][MATRIX_NAME_MAX_CHAR_AMOUNT];

char mat1_name[MATRIX_NAME_MAX_CHAR_AMOUNT];
char mat2_name[MATRIX_NAME_MAX_CHAR_AMOUNT];
char mat3_name[MATRIX_NAME_MAX_CHAR_AMOUNT];

/* Chosen command name */
char command[COMMAND_NAME_MAX_CHAR_AMOUNT];


/* This is a helper function, that gets an input, and determines if the input is a legal command according to the program */
int get_command(char *command) {
    c = getchar();
    i = 0;
    while ((char) c != ' ' && (char) c != '\n' && i < COMMAND_NAME_MAX_CHAR_AMOUNT) {
        *(command + i) = (char) c;
        i++;
        c = getchar();
    }
    *(command + i) = 0; /* Ends the characters of the input */
    return 0;
}

/* This is a helper function, that gets an input, and determines if the input is a legal matrix name according to the program */
int get_mat(char *mat_name) {
    c = getchar();
    while ((char) c == ' ' || (char) c == ',') {
        c = getchar();
    }

    i = 0;
    while ((char) c != ' ' && (char) c != ',' && (char) c != '\n' && i < MATRIX_NAME_MAX_CHAR_AMOUNT) {
        *(mat_name + i) = (char) c;
        i++;
        c = getchar();
    }
    *(mat_name + i) = 0; /* Ends the characters of the input */
    *matChosenNames[k] = mat_name;
    k++;
    return 0;
}

/* This function gets a matrix as a parameter and print's it.*/
int print_mat(mat matrix) {
	printf("\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f       ", matrix[i][j]); /* The desired spaces between the values */
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

/* This function gets a matrix as a parameter, and up to the relevant amount of real numbers from the input buffer,
 * (according to the matrix size). And stores the numbers as the matrix values*/
int read_mat(mat matrix) {
    arguments_read = 0;
    flag = 1; /* As long as the flag is true, the function will keep reading arguments */
    for (i = 0; i < SIZE * SIZE && flag == 1; i++) {
        scanf("%s", str_input);
        printf(" %s", str_input);
        scalar = strtod(str_input, &non_double_extract_from_str);/* Converting the input to double and non-double part(if there is any). */
        /* Only if the non-double part is empty, or if it's a coma, keep reading until the end of the size needed. */
        if (strcmp(non_double_extract_from_str, "") == 0 || strcmp(non_double_extract_from_str, ",") == 0) {
            arguments_for_read_mat[i] = scalar;
            arguments_read++;
            if (strcmp(str_input, "\n") == 0 || getchar() == '\n') {
                break;
            }
        } else if (strcmp(non_double_extract_from_str, "\n") == 0) {
            break;
        } else {
            flag = 0;
        }
    }
    if (flag == 0) {
        printf("invalid arguments, one or more of them are non-real numbers\n");
    } else {
        k = 0;
        for (i = 0; (i < SIZE )&& (flag == 1) && (k < arguments_read); i++) {
            for (j = 0; (j < SIZE) && (flag == 1) && (k < arguments_read); j++) {
                matrix[i][j] = arguments_for_read_mat[k];
                k++;
            }
        }
    }
    fflush(stdin);
    return 0;
}

/* This is the main function that handles the workflow of the matrix calculator program. */
int main() {
    /* Declaring and initializing the 6 matrices. */
    mat MAT_A = {0};
    mat MAT_B = {0};
    mat MAT_C = {0};
    mat MAT_D = {0};
    mat MAT_E = {0};
    mat MAT_F = {0};

    /* Storing the addresses of the matrices in an array, for more accessible usage. */
    mat *matArray[6];
    matArray[0] = &MAT_A;
    matArray[1] = &MAT_B;
    matArray[2] = &MAT_C;
    matArray[3] = &MAT_D;
    matArray[4] = &MAT_E;
    matArray[5] = &MAT_F;

    /* Storing the names of the matrices in an array, for more accessible usage. */
    matNames[0] = "MAT_A"; 
    matNames[1] = "MAT_B";
    matNames[2] = "MAT_C";
    matNames[3] = "MAT_D";
    matNames[4] = "MAT_E";
    matNames[5] = "MAT_F";
    
    /* Storing the names of the matrix calculator commands in an array, for more accessible usage. */
    commandNames[0] = "read_mat";
    commandNames[1] = "print_mat";
    commandNames[2] = "add_mat";
    commandNames[3] = "sub_mat";
    commandNames[4] = "mul_mat";
    commandNames[5] = "mul_scalar";
    commandNames[6] = "trans_mat";
    commandNames[7] = "stop";
    
        	printf("\nPlease enter the command name first, then the arguments for the command.\n follow this template:\nread_mat MAT_X, num1, num2, num3, num4, lastnum\nprint_mat MAT_X\nadd_mat MAT_X, MAT_Y, MAT_Z\nsub_mat MAT_X, MAT_Y, MAT_Z\nmul_mat MAT_X, MAT_Y, MAT_Z\nmul_scalar MAT_X, num, MAT_Y\ntrans_mat MAT_X, MAT_Y\nstop\n");
    
    /* while true (which is always), keep running the program, the program will end once the 'stop' command is given as an input. */
    while (1) {
        fflush(stdin);
		printf("\nPlease enter your command and arguments:\n");
        get_command(&command[0]);
        for (choice = 0; choice < COMMAND_AMOUNT; choice++) {
            if ((strcmp(command, commandNames[choice]) == 0)) {
            	printf("%s ", command);
                break;
            }
        }
        /* All the functions are given a pointer to the matrix for handling. */
        if (choice == 0) { /* Executing 'read_mat' if the matrix name of the input is a legal name. */
            get_mat(&mat1_name[0]);
            for (i = 0; i < MAT_AMOUNT; i++) {
                if ((strcmp(mat1_name, matNames[i]) == 0)) {
                	printf("%s,", mat1_name);
                    read_mat(*matArray[i]);
                    break;
                }
            }
            if (i == MAT_AMOUNT) {
                printf("Undefined matrix name\n");
            }
        } else if (choice == 1) { /* Executing 'print_mat' if the matrix name of the input is a legal name. */
            get_mat(&mat1_name[0]);
            for (i = 0; i < MAT_AMOUNT; i++) {
                if ((strcmp(mat1_name, matNames[i]) == 0)) {
                	printf("%s", mat1_name);
                	print_mat(*matArray[i]);
                    break;
                }
            }
            if (i == MAT_AMOUNT) {
                printf("Undefined matrix name\n");

            }
        } else if (choice == 2 || choice == 3 || choice == 4) { /* Executing 'add_mat', 'sub_mat, or 'mul_mat' if the 3 matrices names of the input are legal. */
            k = 0;
            /* Starting by getting the 3 matrices names, because the 3 function mentioned above share the same arguments */
            get_mat(&mat1_name[0]);
            get_mat(&mat2_name[0]);
            get_mat(&mat3_name[0]);
            for (i = 0; i < MAXIMUM_MATRICES_GIVEN_AS_PARAMETERS; i++) {
                for (j = 0; j < MAT_AMOUNT; j++) {
                    if (strcmp(*matChosenNames[i], matNames[j]) == 0) {
                        matPtrArr[i] = &matArray[j];
                        break;
                    }
                }
                if (j == MAT_AMOUNT) {
                    printf("Undefined matrix name\n");
                }
            }
            switch (choice) { /* Executing the relevant function according to the input choice. */
                case 2:
                	printf("%s, %s, %s",mat1_name, mat2_name, mat3_name);
                    add_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                case 3:
                	printf("%s, %s, %s",mat1_name, mat2_name, mat3_name);
                    sub_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                case 4:
                	printf("%s, %s, %s",mat1_name, mat2_name, mat3_name);
                    mul_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                default:
                    break;
            }
        } else if (choice == 5) { /* Executing 'mul_scalar' if the input is legal. */
            k = 0;
            get_mat(&mat1_name[0]);
            scanf("%lf", &scalar);
            get_mat(&mat2_name[0]);
            for (i = 0; i < MATRIX_AMOUNT_FOR_TRANS_AND_MUL_SCALAR; i++) {
                for (j = 0; j < MAT_AMOUNT; j++) {
                    if (strcmp(*matChosenNames[i], matNames[j]) == 0) {
                        matPtrArr[i] = &matArray[j];
                        break;
                    }
                }
                if (j == MAT_AMOUNT) {
                    printf("Undefined matrix name\n");
                }
            }
            printf("%s, %f, %s",mat1_name, scalar, mat2_name);
            mul_scalar(**matPtrArr[0], scalar, **matPtrArr[1]);
        } else if (choice == 6) { /* Executing trans_mat if the input is legal */
            k = 0;
            get_mat(&mat1_name[0]);
            get_mat(&mat2_name[0]);
            for (i = 0; i < MATRIX_AMOUNT_FOR_TRANS_AND_MUL_SCALAR; i++) {
                for (j = 0; j < MAT_AMOUNT; j++) {
                    if (strcmp(*matChosenNames[i], matNames[j]) == 0) {
                        matPtrArr[i] = &matArray[j];
                        break;
                    }
                }
                if (j == MAT_AMOUNT) {
                    printf("Undefined matrix name\n");
                }
            }
            printf("%s, %s",mat1_name, mat2_name);
            trans_mat(**matPtrArr[0], **matPtrArr[1]);
        } else if (choice == 7) { /* Exit's the program with code 0 - OK */
        	printf("\nYou chose to stop, BYE BYE!\n");
            exit(0);
        } else {
        	if(getchar()==EOF){
        		printf("\nThe file has ended, BYE BYE!\n");
        		exit(0);
        	}
            printf("Undefined command name\n");  
            while(getchar() != '\n'){} /* Keep scanning until the next new line. */
        }
    }
    return 0;
}

