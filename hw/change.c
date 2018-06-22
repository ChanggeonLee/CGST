#include <stdio.h>
int main(){
    int change; // 잔돈
    int C500 = 0 , C100 = 0 , C50 = 0, C10 = 0; // 잔돈을 개수

    // 안내문을 출력하고 잔도을 입력받는다.
    printf("Enter the change.\n");
    scanf("%d", &change);
    

    // 잔돈의 개수를 계산하는 반복문
    while(1){

        if( change-500 >= 0  ){
            // 500원 잔돈의 개수를 계산    
            C500++;
            change-=500;

        }else if(change-100 >= 0){
            // 100원 잔돈의 개수를 계산    
            C100++;
            change-=100;

        }else if(change-50 >= 0){
            // 50원 잔돈의 개수를 계산    
            C50++;
            change-=50;

        }else if(change-10 >= 0){
            // 10원 잔돈의 개수를 계산    
            C10++;
            change-=10;

        }else {
            break ;
        }
    }

    // 잔돈을 출력한다. 
    // 잔돈의 개수가 0개는 출력하지 안하게 하기위서 if문을 만들어준다.
    if(C500 != 0){
        printf("500원 %d개,", C500);
    }
    if(C100 != 0){
        printf("100원 %d개,", C100);
    }
    if(C50  != 0){
        printf("50원 %d개,", C50);
    }
    if(C10  != 0){
        printf("10원 %d개.", C10);
    }

    return 0;
}
