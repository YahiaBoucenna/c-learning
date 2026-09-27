#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head,int data);
struct Node *pop(struct Node *head,int *data);


int main(void){

    

    struct Node *head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    head = push(head,4);
    head = push(head,6);
    head = push(head,8);

    int val;
    head = pop(head,&val);
    head = pop(head,&val);

    printf("head = %d",val);


    




}


struct Node *push(struct Node *head,int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node *pop(struct Node *head,int *value){
    if(head != NULL){
        *value = head->data;
        struct Node *tmp = head->next;
        free(head);
        return tmp;
    }
    return 0;
};
 