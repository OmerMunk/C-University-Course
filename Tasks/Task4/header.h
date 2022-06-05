#define SIZE 10
#define MAX_FILE_NAME_SIZE 2048

typedef struct Node {
    char data[SIZE];
    struct Node *next;
} Node;

int add_node_to_end(Node *head, char data[SIZE]);
int print_linkded_list(Node*);
