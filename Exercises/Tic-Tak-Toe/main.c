#include <stdio.h>
#include "header.h"

int turns;
int i, j, x, y;
int flag;
char player;
int choice;
int result;
int legal;
int choices[9];

int main() {

    printf("Lets Play Tick-Tack-Toe!\n");
    struct xoboard board1 = buildBoard();
    turns = 0;
    player = 'X';
    while (turns != 9) {

        legal = 0;

        while (legal == 0){
            printf("\nThe current board is:\n");
            printBoard(board1);
            printf("player %c, choose where you want to mark:\n", player);
            printChoices();
            scanf("%d", &choice);
            if (choices[choice] == 0)
                legal =1;
            else
                printf("Already taken! choose somewhere else\n\n");
        }
        choices[choice] = 1;
        board1 = mark(board1, choice, player);



        turns++;
        if (player == 'X') {
            result = check(board1, 'X');
        } else {
            result = check(board1, 'O');
        }

        if (result == 1) {
            if (player == 'X') {
                printf("X WON!\n\n");
                printBoard(board1);
                return 0;
            } else {
                printf("O WON!\n\n");
                printBoard(board1);
                return 0;
            }
        }
        if (turns == TURNS) {
            printf("GAME FINISHED, its a tie");
            return 0;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}

struct xoboard mark(struct xoboard board, int num, char which_player) {
    if (num == 1) {
        x = 0;
        y = 0;
    } else if (num == 2) {
        x = 0;
        y = 1;
    } else if (num == 3) {
        x = 0;
        y = 2;
    } else if (num == 4) {
        x = 1;
        y = 0;
    } else if (num == 5) {
        x = 1;
        y = 1;
    } else if (num == 6) {
        x = 1;
        y = 2;
    } else if (num == 7) {
        x = 2;
        y = 0;
    } else if (num == 8) {
        x = 2;
        y = 1;
    } else if (num == 9) {
        x = 2;
        y = 2;
    }

    if (which_player == 'X') {
        board.array[x][y] = 'X';
    } else {
        board.array[x][y] = 'O';
    }

    return board;
}


struct xoboard buildBoard() {
    struct xoboard board = {
            {
                    {'-', '-', '-'},
                    {'-', '-', '-'},
                    {'-', '-', '-'}
            }
    };
    return board;
}


int printBoard(struct xoboard board) {
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c\t", board.array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int printChoices() {
    for (i = 0; i < SIZE * 3; i = i + 3) {
        for (j = 3; j > 0; j--) {
            printf("%d\t", (i + 1 + 3 - j));
        }
        printf("\n");
    }
}


int check(struct xoboard board, char c) {
    for (i = 0; i < SIZE; i++) {
        flag = 1;
        for (j = 0; j < SIZE; j++) {
            if (board.array[i][j] != c) {
                flag = 0;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        flag = 1;
        for (j = 0; j < SIZE; j++) {
            if (board.array[j][i] != c) {
                flag = 0;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }
    flag = 1;
    for (i = 0; i < SIZE; i++) {
        if (board.array[i][i] != c) {
            flag = 0;
        }
    }
    if (flag == 1) {
        return 1;
    }
    flag = 1;
    for (i = 0, j = 2; i < SIZE && j >= 0; i++, j--) {
        if (board.array[i][j] != c) {
            flag = 0;
        }
    }
    if (flag == 1) {
        return 1;
    }
    return 0;
}












