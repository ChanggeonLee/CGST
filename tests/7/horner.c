#include <stdio.h>

// horner법을 이용하여 값을 계산하는 함수
double horner(int n , double p[] , double x){
    double result ; // 결과 값

    result = p[0];
    // n 만큼 반복
    for(int i  = 1 ; i <= n ; i++){
        // result * x 를 하고 p[i]을 더해준다.
        result = (result * x)+p[i];
    }
    
    // 결과 값을 반환
    return result;
}


int main(){
    int n; //차수를 저장
    double p[100]; // 최대로 저장 할수 있는 소수를 100개로 가정
    double x ; // x값
    double result;

    // n , p , x값을 입력 받는다.
    printf("Enter order and coefficients.\n");
    scanf("%d" , &n);
    for(int i = 0 ; i <= n ; i++){
        scanf("%lf" , &p[i]);
    }
    scanf("%lf" , &x);

    // horner법을 이용해서 값을 구한다.
    result = horner(n , p , x);

    printf("The answer is %.3lf\n" , result);
    return 0;
}
