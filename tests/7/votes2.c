#include <stdio.h>
int check(int votes[100] , int n , int count_all){
    int i;
    int n_count=0;
    for( i = 0; i < count_all ; i++){
        if(n == votes[i]){
            n_count++;
        }
    }
    if( (count_all/2) < n_count){
        return 1;
    }
    return 0;
}

int main(){
    int vote = 0; // 투표
    int votes[100]; 
    int count_all = 0 ; // 전체표 수
    int temp; // 입력 받는 임시 변수
    printf("Enter the votes\n");
    
    // vote 값이 -1이 나오면 종료
    scanf("%d" , &temp);
    while(temp != -1){
        votes[count_all] = temp;

        if(vote == 0 ){
            vote = temp;
        }else if(vote != temp){
            vote = 0;
        }
        count_all++;
        scanf("%d" , &temp);
    }

    if(vote == 1 && check(votes , vote , count_all) == 1){
        printf("Number 1 is the winner\n");
    }else if(vote == 2 && check(votes , vote , count_all) == 1){
        printf("Number 2 is the winner\n");
    }else if(vote == 3 && check(votes , vote , count_all) == 1){
        printf("Number 3 is the winner\n");
    }else{
        printf("No elected\n");
    }

    return 0;
}
