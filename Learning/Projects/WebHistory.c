#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char Url[100];
    struct Node *next;
    struct Node *prev;
};

struct Node *visit(struct Node *head,const char *WebUrl);
struct Node *back(struct Node *head);
struct Node *forward(struct Node *Current_page);

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    strcpy(head->Url,"New Page");
    head->prev = NULL;
    head->next = NULL;

    head = visit(head,"www.youtube.com");
    head = visit(head,"www.google.com");
    struct Node *Current_page = head;
    Current_page = back(Current_page);
    Current_page = back(Current_page);

    Current_page = forward(Current_page);
    
    printf("%s\n",Current_page->Url);

    return 0;
}

struct Node *visit(struct Node *head,const char *WebUrl){
    struct Node *NewWindow = malloc(sizeof(struct Node));
    strcpy(NewWindow->Url,WebUrl);
    NewWindow->prev = NULL;
    NewWindow->next = head;
    head->prev = NewWindow;
    return NewWindow;
}

struct Node *back(struct Node *head){
    struct Node *current_page = head;
    if(head->next != NULL){
        current_page = current_page->next;
        return current_page;
    }else{
        return current_page;
    }
}

struct Node *forward(struct Node *Current_page){
    if(Current_page->prev != NULL){
        Current_page = Current_page->prev;
        return Current_page;
    }else{
        return Current_page;
    }
}
