/* Written by Omer Munk */

/* Including the relevant libraries and header used for this program. */
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Declerations of variables used for this program. */
char* file_name; /* This variable will be used store the file_name given as a command line argument. */
FILE *fp; /* This variable will store a pointer to the file to read. */
int c, i; /* c will be used to store the characters of the input, and i for indexing loops. */

/* head is the pointer to the begining of the linked list.
newNode will be a new created node every time it is needed.
and current is a handler pointer for adding new nodes and printing the data. */
Node *head, *newNode, *current; 
char new_data[SIZE]; /* new_data will hold the data of a new_created node. */

/* This function creates and add a new node with a given data to the end of the linked list.
parameters:
head: A Node pointer to the begining of a linked list.
data: An array of characters that stores the data that the new node created should hold. */
int add_node_to_end(Node *head, char data[SIZE]) {
    current = head;
    while (current->next != NULL) {
    	/* Keep moving forward up the linked list until it gets to the last node. */
        current = current->next;
    }
    /* Reached the last node, adding a new one with the data given as a parameter. */
    newNode = NULL; /* Resetting the new Node */
    newNode = (Node *) malloc(sizeof(struct Node)); /* Allocating the memory needed. */
    /* Adding the data */
    for (i = 0; i < SIZE; i++) {
        newNode->data[i] = data[i];
    }
    current->next = newNode;
    current->next->next = NULL;
    return 0;
}

/* This function prints the whole data that a linked list contain.
parmeter:
head: A Node pointer to the begining of a linked list. */
int print_linked_list(Node *head) {
    current = head;
    while (current->next != NULL) {
        for (i = 0; i < SIZE && current->data[i]!=EOF; i++) {
            printf("%c ", current->data[i]);
        }
        current = current->next;
        printf("\n");
    }
    for (i = 0; i < SIZE && current->data[i]!=EOF; i++) {
        printf("%c ", current->data[i]);
    }
    printf("\n");
    
    return 0;
}

/* This is the main function of the program, that handles the whole workflow of this section of the project. */
int main(int argc, char* argv[]) {
	file_name = (char*)malloc(sizeof(char)* MAX_FILE_NAME_SIZE);
    file_name = argv[1];
    fp = fopen(file_name, "r");
    head = NULL;
    head = (Node *) malloc(sizeof(struct Node));
	head->next = NULL;
    c = getc(fp);
    while (c != EOF) {
        i = 0;
        while (i < SIZE && c != EOF) {
            new_data[i] = (char) c;
            c = getc(fp);
            i++;
        }
       	while (i < SIZE){
       		new_data[i] = EOF;
       		i++;
       	}
        add_node_to_end(head, new_data);
    }
    print_linked_list(head);
    fclose(fp);
    return 0;
}
