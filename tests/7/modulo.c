#include <stdio.h>
#include <string.h>


// 모듈려 연산을 하는 함수
int modulo(char num[] , int m){
    int result=0; // 결과값을 저장할 변수
    
    // 모듈려 연산 한다.
    for(int i = 0 ; i < strlen(num) ; i++){
        result = (result*10 + (num[i]-48)) % m;
    }
    // 결과값을 반환한다.
    return result;
}

int main(){
    char long_integer[100]; // long값
    int m; // 모듈러 연산할 값
    int result = 0; // 결과값
    
    // 연산할 값을 입력 받는다
    printf("Enter a big positive integer and m.\n");
    scanf("%s" , long_integer);
    scanf("%d" , &m);


    // 연산한 결과를 저장하고 출력
    result = modulo(long_integer , m);
    printf("%s %% %d is %d" , long_integer , m , result);
    return 0;
}
