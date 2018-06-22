#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
   
    while(1){
        printf("Enter an id.\n");
        scanf("%s", str);
        if(strcmp(str,"1")==0){
           break;
        }else if(strlen(str) > 3){
            printf("It‘s illegal.\n");
        }else if(97 > str[0] || str[0] > 122){
            printf("It‘s illegal.\n");
        }else if( (48>str[1] || str[1]>57) && (48>str[2] || str[2]>57)){
            printf("It‘s illegal.\n");
        }else {
            printf("It‘s legal.\n");
        }
    }

    return 0;
}
