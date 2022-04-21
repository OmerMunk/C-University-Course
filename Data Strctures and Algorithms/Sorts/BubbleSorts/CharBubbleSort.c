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
