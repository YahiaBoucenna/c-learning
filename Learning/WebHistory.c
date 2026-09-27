#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char Url[100];
    struct Node *next;
};

struct Node *visit(struct Node *Current_page,const char *WebUrl);

int main(){
    struct Node *Current_page = malloc(sizeof(struct Node));
    strcpy(Current_page->Url,"New Page");
    Current_page->next = NULL;

    Current_page = visit(Current_page,"www.youtube.com");
    
    printf("%s",Current_page->Url);

    return 0;
}

struct Node *visit(struct Node *Current_page,const char *WebUrl){
    struct Node *NewWindow = malloc(sizeof(struct Node));
    strcpy(NewWindow->Url,WebUrl);
    NewWindow->next = Current_page;
    return NewWindow;
}
