#include<stdio.h>
#include<math.h>

int main(){
    int max_len; // 삼각형의 최대 길이
    int a , b , c; // 변의 길이
    int temp; // 임시변수

    // 삼각형의 최대 길이를 입력 받는다.
    printf("Enter the maximum length N.\n");
    scanf("%d" , &max_len);

    // a , b, c 변의 길이를 구한다.
    printf("The right-angled triangles are,\n");

    // 0부터 max_len 만큼 반복하여 삼각형의 한변의 길이를 넣어본다.
    for(int i = 1 ; i < max_len ; i++){
        a = i;
        for(int j = 1 ; j < max_len ; j++){
            // a 값에 대한 b값과 c값이 성립하는지 확인
            b = j;
            temp = a * a + b * b ;
            c = sqrt(temp); // 제곱근을 구하는 라이브러리 함수를 사용
            
            // c값이 최대길이보다 작고 c값이 정수인지 확인하여 출력
            if(c < max_len && temp == c*c){
                printf("%d , %d ,%d\n ", a , b , c);
            }
        }
    }

    return 0;
}
