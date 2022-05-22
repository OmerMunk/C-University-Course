#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4
#define MAT_AMOUNT 6
#define COMMAND_NAME_MAX_CHAR_AMOUNT 11
#define MATRIX_NAME_MAX_CHAR_AMOUNT 6
#define COMMAND_AMOUNT 8

typedef double mat[SIZE][SIZE];

int i, j, c, choice, flag;
int k = 0;
double scalar;
double arguments_for_read_mat[SIZE * SIZE];
int arguments_read;
char str_input[20]; // double can hold 8 bytes, which is 64 bits, which is 2^64, that number has 20 digits max.
char *non_double_extract_from_str;
mat *mat1Ptr;
mat *mat2Ptr;
mat *mat3Ptr;
mat **matPtrArr[3] = {&mat1Ptr, &mat2Ptr, &mat3Ptr};
char *matChosenNames[3][MATRIX_NAME_MAX_CHAR_AMOUNT];
\

mat tempMat = {0};

int add_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return 0;
}

int sub_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return 0;
}

int mul_mat(mat mat1, mat mat2, mat mat3) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 0;
}

int mul_scalar(mat mat1, double given_scalar, mat mat2) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            mat2[i][j] = mat1[i][j] * given_scalar;
        }
    }
    return 0;
}

int trans_mat(mat mat1, mat mat2) {
    if (mat1 == mat2){
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

int get_command(char *command) {
    c = getchar();
    i = 0;
    while ((char) c != ' ' && (char) c != '\n' && i < COMMAND_NAME_MAX_CHAR_AMOUNT) {
        *(command + i) = (char) c;
        i++;
        c = getchar();
    }
    *(command + i) = 0;
    return 0;
}

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
    *(mat_name + i) = 0;
    *matChosenNames[k] = mat_name;
    k++;
    return 0;
}

int print_mat(mat matrix) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2lf       ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int read_mat(mat matrix) {
    arguments_read = 0;
    flag = 1;
    for (i = 0; i < SIZE * SIZE && flag == 1; i++) {
        scanf("%s", str_input);

        scalar = strtod(str_input, &non_double_extract_from_str);
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
        for (i = 0; i < SIZE && flag == 1 && k < arguments_read; i++) {
            for (j = 0; j < SIZE && flag && k < arguments_read == 1; j++) {
                matrix[i][j] = arguments_for_read_mat[k];
                k++;
            }
        }
    }
    fflush(stdin);
    return 0;
}

int main() {
    mat MAT_A = {0};
    mat MAT_B = {0};
    mat MAT_C = {0};
    mat MAT_D = {0};
    mat MAT_E = {0};
    mat MAT_F = {0};

    mat *matArray[6] = {&MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F};

    char matNames[MAT_AMOUNT][MATRIX_NAME_MAX_CHAR_AMOUNT] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
    char commandNames[COMMAND_AMOUNT][COMMAND_NAME_MAX_CHAR_AMOUNT] = {"read_mat", "print_mat", "add_mat", "sub_mat",
                                                                       "mul_mat", "mul_scalar", "trans_mat",
                                                                       "stop"};
    char command[COMMAND_NAME_MAX_CHAR_AMOUNT];
    char mat1_name[MATRIX_NAME_MAX_CHAR_AMOUNT];
    char mat2_name[MATRIX_NAME_MAX_CHAR_AMOUNT];
    char mat3_name[MATRIX_NAME_MAX_CHAR_AMOUNT];

    int o = 1;
    while (1) {
        fflush(stdin);
        printf("iteration number %d\n", o);
        o++;
        get_command(&command[0]);
        for (choice = 0; choice < COMMAND_AMOUNT; choice++) {
            if ((strcmp(command, commandNames[choice]) == 0)) {
                printf("command ok\n");
                break;
            }
        }
        if (choice == 0) {
            get_mat(&mat1_name[0]);
            for (i = 0; i < MAT_AMOUNT; i++) {
                if ((strcmp(mat1_name, matNames[i]) == 0)) {
                    printf("mat name ok\n");
                    read_mat(*matArray[i]);
                    break;
                }
            }
            if (i == MAT_AMOUNT) {
                printf("Undefined matrix name\n");
            }
        } else if (choice == 1) {
            get_mat(&mat1_name[0]);
            for (i = 0; i < MAT_AMOUNT; i++) {
                if ((strcmp(mat1_name, matNames[i]) == 0)) {
                    printf("mat name ok\n");
                    print_mat(*matArray[i]);
                    break;
                }
            }
            if (i == MAT_AMOUNT) {
                printf("Undefined matrix name\n");

            }
        } else if (choice == 2 || choice == 3 || choice == 4) {
            k = 0;
            get_mat(&mat1_name[0]);
            get_mat(&mat2_name[0]);
            get_mat(&mat3_name[0]);
            for (i = 0; i < 3; i++) {
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
            switch (choice) {
                case 2:
                    add_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                case 3:
                    sub_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                case 4:
                    mul_mat(**matPtrArr[0], **matPtrArr[1], **matPtrArr[2]);
                    break;
                default:
                    break;
            }
        } else if (choice == 5) {
            k = 0;
            get_mat(&mat1_name[0]);
            scanf("%lf", &scalar);
            get_mat(&mat2_name[0]);
            printf("\n%s\n", mat2_name);
            for (i = 0; i < 2; i++) {
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
            mul_scalar(**matPtrArr[0], scalar, **matPtrArr[1]);
        } else if (choice == 6) {
            k = 0;
            get_mat(&mat1_name[0]);
            get_mat(&mat2_name[0]);
            for (i = 0; i < 2; i++) {
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
            trans_mat(**matPtrArr[0], **matPtrArr[1]);
        } else if (choice == 7) {
            exit(202);
        } else {
            printf("Undefined command name\n");
        }
    }
    return 0;
}
