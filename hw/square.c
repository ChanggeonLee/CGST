#include <stdio.h>

// 제곱수를 구해주는 함수
int power(int a , int b){
    int result = 1;
    // b번 반큼 a를 곱해준다.
    for(int i = 0 ; i < b ; i++){
        result *= a;
    }

    // a^b값을 반환해준다.
    return result;
}


int main() {
    int a, b; // 두개의 정수
    int result ; // a^b의 값

    // 두정수를 입력 받는다.
    printf("Enter base and power.\n");
    scanf("%d %d" , &a , &b);
 
    // power를 호출하여 a^b값을 받는다.
    result = power(a , b);
    
    // a^b값을 출력한다.
    printf("%d to the %d is %d.\n", a , b, result);

    return 0;
}
