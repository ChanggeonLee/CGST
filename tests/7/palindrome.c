#include <stdio.h>
#include <string.h>

int main(){
    char str[100]; // 입력받은 문자열
    int max_len; // str의 길이
    int num = 0; // 임시변수

    // 문자를 입력
    printf("Enter input.\n");
    scanf("%s" , str);

    while(strcmp(str , "quit") != 0){
        max_len = strlen(str);
        max_len--;

        // 회문인지 아닌지 판별
        while(max_len >= 0 ){    
            if(str[num] != str[max_len]){
                printf("No, it is NOT a palindrome.\n");
                break;
            }
            num++;
            max_len--;
        }
        
        // 회문이면 max_len 값이 -1이다
        if(max_len == -1){
            printf("Yes, it is a palindrome.\n");
        }
        scanf("%s" , str);
        num = 0;
    }
    return 0;
}
