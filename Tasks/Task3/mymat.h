
/* Defining of the constant numbers in the program. */
#define SIZE 4
#define MAT_AMOUNT 6
#define COMMAND_NAME_MAX_CHAR_AMOUNT 11
#define MATRIX_NAME_MAX_CHAR_AMOUNT 6
#define COMMAND_AMOUNT 8
#define DOUBLE_MAXIMUM_DIGITS 20
#define MAXIMUM_MATRICES_GIVEN_AS_PARAMETERS 3
#define MATRIX_AMOUNT_FOR_TRANS_AND_MUL_SCALAR 2

/* Type definition of matrix - two-dimensional array that contains real-numbers(double)  */
typedef double mat[SIZE][SIZE];

int add_mat(mat, mat, mat);
int sub_mat(mat, mat, mat);
int mul_mat(mat, mat, mat);
int mul_scalar(mat, double, mat);
int trans_mat(mat, mat);
int get_commad(char*);
int get_mat(char*);
int print_mat(mat);
int read_mat(mat);

