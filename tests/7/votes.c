#include <stdio.h>

int main(){
    int count_1 = 0; // 기호 1번의 득표수
    int count_2 = 0; // 기호 2번의 득표수
    int count_3 = 0; // 기호 3번의 득표수
    
    int vote ; // 투표

    int count_all; // 모든 투표 수

    printf("Enter the votes\n");
    
    // 투표를 진행 한다.
    // vote 값이 -1이 나오면 종료
    scanf("%d" , &vote);
    while(vote != -1){
        if(vote == 1){
            count_1++;
        }else if(vote == 2){
            count_2++;
        }else if(vote ==3){
            count_3++;
        }
        scanf("%d" , &vote);
    }

    count_all = count_1 + count_2 + count_3;
    
    // 단선자를 확인
    if(count_1 > count_2 && count_1 > count_3 && (count_all / 2) < count_1 ){
        printf("Number 1 is the winner\n");
    }else if(count_2 > count_1 && count_2 > count_3 && (count_all / 2) < count_2 ){
        printf("Number 2 is the winner\n");
    }else if(count_3 > count_1 && count_3 > count_2 && (count_all / 2) < count_3 ){
        printf("Number 3 is the winner\n");
    }else {
        printf("No elected\n");
    }

    return 0;
}
