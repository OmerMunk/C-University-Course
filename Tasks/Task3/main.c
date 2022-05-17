#include <stdio.h>
#include <string.h>

#define SIZE 4
#define MAT_AMOUNT 6

typedef double mat[SIZE][SIZE];
typedef mat* matPtr;

mat MAT_A = {0};
mat MAT_B = {0};
mat MAT_C = {0};
mat MAT_D = {0};
mat MAT_E = {0};
mat MAT_F = {0};

matPtr matArray[6]= {&MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F};
char matNames[6][5] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
int i, j;




int print_mat(matPtr matrix) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2lf       ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int read_mat() {
    char matName[5];
    printf("type which matrix to execute the command on.\n");
    fflush(stdin); /*TODO: but its not good if the input is from a file*/
    scanf("%s", &matName);
    if ((strcmp(matName, "MAT_A") == 0)) {
        printf("GOOD\n");

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++){
                scanf("%lf",&MAT_A[i][j]);
                if(MAT_A[i][j] == EOF){
                    printf("end");
                    break;
                }
            }
        }
    }
    return 0;
}

int add_mat(){
    printf("type 3 matrix\n");
    matPtr m1;
    matPtr m2;
    matPtr m3;
    char mat1[5];
    char mat2[5];
    char mat3[5];
    printf("type the 1st matrix\n");

    scanf("%s", &mat1);
    printf("type the 2nd matrix\n");

    scanf("%s", &mat2);
    printf("type the 3rd matrix\n");

    scanf("%s", &mat3);

    for(i = 0 ; i < MAT_AMOUNT ; i++ ){
        if ((strcmp(mat1, matNames[i]) == 0)){
            m1 = matArray[i];
        }
    }
    printf("finish first loop");
    for(i = 0 ; i < MAT_AMOUNT ; i++ ){
        if ((strcmp(mat2, matNames[i]) == 0)){
            m2 = matArray[i];
        }
    }
    for(i = 0 ; i < MAT_AMOUNT ; i++ ){
        if ((strcmp(mat3, matNames[i]) == 0)){
            m3 = matArray[i];
        }
    }
    printf("finished the for loops");
    print_mat(m1);
    printf("\n");
    print_mat(m2);
    printf("\n");
    print_mat(m3);
    printf("finished printing");
}


int main() {


    printf("Which command would you like to do?");

    char command[15];
    scanf("%s", &command);
    while (strcmp(command, "exit") != 0){
        if (strcmp(command, "read_mat") == 0) {
            read_mat();
        }else if ((strcmp(command, "add_mat") == 0)){
            add_mat();
        } else {
            printf("Invalid input, try again\n");
        }
        printf("Which command would you like to do?\n");
        scanf("%s\n", &command);
    }
    printf("Bye Bye\n");




    return 0;
}

