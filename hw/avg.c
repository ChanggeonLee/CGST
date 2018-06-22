#include <stdio.h>

int main(){
    int num;// 정수
    int num_count=1; // 입력된 정수의 개수
    float avg = 0;  // 평균 값

    // 평균 계산을 위한 반복문
    while (1) {
        // 안내문을 출력 후 정수 값을 입력 받는다
        printf("Enter an integer.\n");
        scanf("%d" , &num);

        if( num <= 0 && avg == 0  ){
        // 첫번째 입력 받은 수가 0이거나 음수이면 반복을 멈추고 끝낸다.
            printf("Current average is 0.000.\n");
            break;
        }else if(num > 0){
            // 입력 받은 수가 정수이면평균을 계산하여 출력한다.
            avg += num;
            avg /= num_count;
            num_count++;
            printf("Current average is %.3f\n", avg); 
        }else{
            // 입력받은수가 정수가 아니면 반복을 멈추고 끝낸다.
            break;
        }

    }

    return 0;
}
