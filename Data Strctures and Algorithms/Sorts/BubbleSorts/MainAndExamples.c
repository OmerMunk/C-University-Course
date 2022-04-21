//
// Created by Omer Munk.
//

#include <stdio.h>

// set of function for regular integers bubble sort
// START

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr1[]) {
    int n = sizeof(arr1);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swap(&arr1[j], &arr1[j + 1]);
            }
        }
    }
}

void printArray(int arr1[]) {
    int n = sizeof(arr1);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");
}
// END



// set of function for char's bubble sort
// START
void swapChar(char *xp, char *yp) {
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSortChar(char arr1[]) {
    int n = sizeof(arr1);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swapChar(&arr1[j], &arr1[j + 1]);
            }
        }
    }
}

void printArrayChar(char arr1[]) {
    int n = sizeof(arr1);
    int i;
    for (i = 0; i < n; i++)
        printf("%c ", arr1[i]);
    printf("\n");
}
// END



// set of function for "strings" ASCII sum bubble sort
// START
void swapWords(char xp[], char yp[]) {
    int n = sizeof xp;
    char temp[n];
    int i;
    for (i = 0; i < n ; i++){
        temp[i] = xp[i];
    }
    for (i = 0; i < n ; i++){
        xp[i] = yp[i];
    }
    for (i = 0; i < n ; i++){
        yp[i] = temp[i];
    }
}

int ASCIISum(char arr1[]) {
    int n = sizeof (arr1);
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        int ascii = arr1[i];
        sum = sum + ascii;
    }
    return sum;
}

void bubbleSortASCIIValue(char arr1[5][10]) {
    int i;
    for (i = 0; i < 5; i++) {
        int j;
        for(j = 0 ; j < 5-i-1 ; j++){
            if (ASCIISum(arr1[j]) > ASCIISum(arr1[j + 1])) {
                swapWords(arr1[j], arr1[j + 1]);
            }
        }
    }
}

void printArrayWords(int n,int m, char arr1[n][m]) {
    int i;
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < m; j++) {
            printf("%c", arr1[i][j]);
        }
    }
    printf("\n");
}
// END



int main() {
    int arr1[] = {6, 7, 5, 8, 4, 9, 2, 3, 1};
    printf("Example of integers bubble sort\n");
    printArray(arr1);
    bubbleSort(arr1);
    printArray(arr1);
    printf("\n");

    char arr2[] = {'x', 't', 'z', 'b', 'c', 'd', 'y', 'a'};
    printf("Example of char's bubble sort\n");
    printArrayChar(arr2);
    bubbleSortChar(arr2);
    printArrayChar(arr2);
    printf("\n");

    char ch_arr[5][10] = {
            "zzz",
            "www",
            "def",
            "defg",
            "abc"
    };
    int n = sizeof (ch_arr)/sizeof (ch_arr[0]);
    int m = sizeof (ch_arr[0]);
    printf("Example of \"Strings\" ASCII sum bubble sort\n");
    printArrayWords(n, m, ch_arr);
    bubbleSortASCIIValue(ch_arr);
    printArrayWords(n, m, ch_arr);
    return 0;
}
