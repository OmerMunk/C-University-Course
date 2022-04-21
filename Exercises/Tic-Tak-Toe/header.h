struct xoboard {
    char array[3][3];
};

#define SIZE 3
#define TURNS SIZE*SIZE

struct xoboard mark(struct xoboard ,int, char);
int check(struct xoboard , char );
int printBoard(struct xoboard board);
int printChoices();
struct xoboard buildBoard();
