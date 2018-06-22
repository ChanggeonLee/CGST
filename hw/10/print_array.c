#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
void print_array(char *arr , int length){
    if(length >= 0 ){
        printf("%c", *arr);
        length --;
        arr = arr + 1;
        print_array(arr , length);
    }else{
        printf("\n");
    }
    return ;
}

int main(){
    
    char * str;
    char temp[MAX];

    printf("문자를 입력해주세요\n");
    scanf("%s" , temp);

    str = (char*)malloc(sizeof(strlen(temp)));
    strcpy(str , temp);    
    print_array(str, strlen(str));
    
    return 0;
}
