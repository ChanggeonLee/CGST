#include  <stdio.h>

void move(int N , char X, char Y , char Z){
    if( N == 1 ) {
        printf("move a disk from %c to %c\n", X ,Y);
    }else{
        move(N-1 , X , Z , Y);
        move(1 , X , Y , Z);
        move(N-1 , Z, Y , X);

    }
    return ;
}


int main(){
    int n ; // 원판의 개수
    printf("Enter the number N\n");
    scanf("%d" , &n);
    move(n , 'X' , 'Y' ,'Z');
    return 0;
}
