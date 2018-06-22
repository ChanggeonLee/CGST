#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void swap(char ** p){
    char temp[MAX];
    
    strcpy(temp , p[0]);
    strcpy(p[0] , p[1]);
    strcpy(p[1] , temp);
}


int main(){
    char ** p;
    char temp[MAX];

    p = (char**)malloc(2);
    
    printf("1번 이름 입력:");
    scanf("%s",temp);
    p[0] = (char *)malloc(sizeof(strlen(temp)));
    strcpy(p[0] , temp);

    printf("2번 이름 입력:");
    scanf("%s",temp);
    p[1] = (char *)malloc(sizeof(strlen(temp)));
    strcpy(p[1] , temp);

    swap(p);

    printf("%s\n" , p[0]);
    printf("%s\n" , p[1]);

    free(p);

    return 0;
}
