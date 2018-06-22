#include <stdio.h>

int main (){
    char str[100]; // 문자열 
    int count = 0; // 모음의 개수

    // 문자열을 입력 받는다.
    printf("Enter a sentence.\n");
    gets(str);

    // 문자열 하나씩 비교하면서 모음의 개수를 체크한다.
    for (int i = 0 ; str[i] != 0 ; i++){
        if(str[i] == 'a' || str[i] == 'A'){
            count++;
        }else if(str[i] == 'e' || str[i] == 'E'){
            count++;
        }else if(str[i] == 'i' || str[i] == 'I'){
            count++;
        }else if(str[i] == 'o' || str[i] == 'O'){
            count++;
        }else if(str[i] == 'u' || str[i] == 'U'){
            count++;
        }
    }
    
    // 모음의 개수를 출력한다.
    printf("Vowels appear %d times." , count);
    return 0;
}
