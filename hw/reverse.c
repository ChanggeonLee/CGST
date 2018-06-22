#include <stdio.h>

// 입력 받은 정수를 뒤집어주는 함수
void reverse_it(int num){
    int revers_int = 0; // 뒤집은 정수
    int last_int; // 마지막자리 정수

    // 정수의 값이 0이 될때까지 반복 한다.
    while(num != 0){
        last_int = num % 10; // 마지막자리의 정수를 추출
        revers_int = (revers_int * 10) + last_int; // 뒤집은 정수 값에 저장해준다.
        num /= 10; // 마지막 자리수를 지워준다
    }
    // 뒤집은 정수르 출력한다.
    printf("%d\n",revers_int);
    return ;
}

int main() {
    int num; // 정수

    while(1){
        // 뒤집을 정수를 입력 받는다.
        printf("Enter an integer.\n");
        scanf("%d",&num);

        // 입력 받은 정수가 0 이하면 반복을 멈추고 끝낸다.
        if(num <= 0){
            break;
        }
        // 정수를 뒤집어주는 함수를 호출해준다.
        reverse_it(num);
    }

    return 0;
}
