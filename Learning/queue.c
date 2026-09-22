#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct queue{
    struct Node *head;
    struct Node *tail;
};

void enqueue(struct queue *q,int data);
int dequeu(struct Node *head,int *data);


int main(void){
    


}
void enqueue(struct queue *q,int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->head != NULL){
        q->tail->next = newNode;
        q->tail = newNode;
    }else{
        q->head = newNode;
        q->tail = newNode;
    }   
}

