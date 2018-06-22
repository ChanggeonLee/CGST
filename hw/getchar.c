#include <stdio.h>
#include <string.h>
int main(){
    int c;
    int i = 0;
    char str[100];
    
    c = getchar();
    while(c != EOF && c != 10 && c != 32 ){
        str[i] = c;
        i++;
        c = getchar();
    }
    str[i] = 0 ;
    
    printf("%s\n" , str);

    return 0;
}



