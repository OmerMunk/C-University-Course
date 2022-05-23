#include <stdio.h>
#include "mymat.h"

/* Declerations of variable used in the functions. */
int i, j, k; /* i, j, and k are used as loop iterations index. */


/* A temporary matrix for handling the transpose command for two identical matrices */
mat tempMat = {0};


/* This function gets 3 matrices, and executes matrices addition.
 * It adds matrix 1 to matrix 2 and stores the result in matrix 3.  */
int add_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return 0;
}

/* This function gets 3 matrices, and executes matrices subtraction.
 * It subtracts matrix 2 from matrix 1 and stores the result in matrix 3.  */
int sub_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return 0;
}

/* This function gets 3 matrices, and executes matrices multiplication.
 * It multiplies matrix 1 and matrix 2 and stores the result in matrix 3  */
int mul_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
        	mat3[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 0;
}


/* This function gets 2 matrices, and a real-scalar, and executes scalar multiplication.
 * It multiplies each one of the values of matrix1, by the given scalar, and stores the new matrix in matrix 2. */
int mul_scalar(mat mat1, double given_scalar, mat mat2) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat2[i][j] = mat1[i][j] * given_scalar;
        }
    }
    return 0;
}


/* This function gets 2 matrices, and stores the transpose of matrix 1, and matrix 2.
 * it can handle the operation on two identical matrices by using a temporary matrix*/
int trans_mat(mat mat1, mat mat2) {
    if (mat1 == mat2){ /* 'mat1==mat2' means that the both matrices are identical, therefore, it is needed to use a third temp matrix. */
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                tempMat[i][j] = mat1[i][j];
            }
        }
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                mat2[i][j] = tempMat[j][i];
            }
        }
    }else{
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                mat2[i][j] = mat1[j][i];
            }
        }
    }
    return 0;
}
