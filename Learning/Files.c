#include<stdio.h>
#include<string.h>

struct student {
    char name[50];
    int age;
    float grade;
};

int main(void){
    struct student s;

    strcpy(s.name , "yahia");
    s.age = 20;
    s.grade = 18;

    FILE *file = fopen("student.txt", "wb");
    if(file == NULL){
        printf("no write permission in that folder");
        return 1;
    }
    fwrite(&s,sizeof(struct student),1,file);
    fclose(file);

    struct student p;
    FILE *ptr = fopen("student.txt","rb");
    if(ptr == NULL){
        printf("no write permission in that folder");
        return 1;
    }
    fread(&p,sizeof(struct student),1,ptr);
    printf("%s\n %d\n %f",p.name,p.age,p.grade);
    fclose(ptr);

    return 0;
}