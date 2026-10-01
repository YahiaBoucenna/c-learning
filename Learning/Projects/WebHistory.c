#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char URL[200];
    struct Node *next;
    struct Node *prev;
};

struct Node *visit(struct Node *head,const char *WebURl);
struct Node *back(struct Node *head);
struct Node *forward(struct Node *head);

int main(void){

    struct Node *head = malloc(sizeof(struct Node));
    strcpy(head->URL,"New Tab");
    head->prev = NULL;
    head->next = NULL;

    head = visit(head,"www.youtube.com");
    head = visit(head,"www.facebook.com");
    head = visit(head,"www.tiktok.com");
    head = visit(head,"www.x.com");
    head = back(head);
    head = back(head);
    head = forward(head);
    head = forward(head);
    head = forward(head);
    printf("%s\n",head->URL);
    


}
struct Node *visit(struct Node *head,const char *WebURl){
    if(head->prev == NULL){
        struct Node *NewNode = malloc(sizeof(struct Node));
        NewNode->next = head;
        NewNode->prev = NULL;
        strcpy(NewNode->URL, WebURl);
        head->prev = NewNode;
        return NewNode;
    }else{
        printf("please move forward");
        return head; 
    }
}

struct Node *back(struct Node *head){
    if(head->next != NULL){
        struct Node *tmp = head;
        head = head->next;
        head->prev = tmp;
        return head;
    }else{
        return head;
    }
}

struct Node *forward(struct Node *head){
    if(head->prev != NULL){
        head = head->prev;
        return head;
    }else{
        return head;
    }
}
