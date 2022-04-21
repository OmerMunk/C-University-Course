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
