#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_pardoms(int **p , int row , int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
           printf("%d " ,p[i][j]); 
        }
        printf("\n");
    }
}

int main(){
    
    int **A;
    int a_row , a_col;

    int **B;
    int b_row , b_col;

    int **S;
    int s_row , s_col;

    int temp;

    int sum;
    
    printf("A의 행 과 열을 입력하세요:");
    scanf("%d%d", &a_row , &a_col);

    A = (int **)malloc(sizeof(int*) * a_row);
    printf("A의 행렬의 원소를 입력하세요:");
    for(int i = 0 ; i < a_row ; i++){
        A[i] = (int*)malloc(sizeof(int) * a_col);
        for(int j = 0 ; j < a_col ; j++){
            scanf("%d" , &A[i][j]);
        }
    }
    printf("행렬A\n");
    print_pardoms(A , a_row , a_col);   
   

    printf("B의 행 과 열을 입력하세요:");
    scanf("%d%d", &b_row , &b_col);
    
    B = (int **)malloc(sizeof(int*) * b_row);
    printf("B의 행렬의 원소를 입력하세요:");
    for(int i = 0 ; i < b_row ; i++){
        B[i] = (int*)malloc(sizeof(int) * b_col);
        for(int j = 0 ; j < b_col ; j++){
            scanf("%d" , &temp);
            B[i][j] = temp;
        }
    }
    printf("행렬B\n");
    print_pardoms(B , b_row , b_col);   
    

    if( a_col == b_row ){
        s_row = a_row;
        s_col = b_col;
        
        int key = a_col;
        
        S = (int **)malloc(sizeof(int*) * s_row);
        for(int i=0; i<s_row; i++){
            S[i] = (int*)malloc(sizeof(int) * s_col);
            for(int j=0; j<s_col; j++){
                sum=0;
                for(int k=0; k<key; k++){
                    sum+=A[i][k]*B[k][j];
                }
                S[i][j]=sum;
            }
        }

        
    }else{
        printf("곱하기 못해\n");

    }
    printf("행렬S\n");
    print_pardoms(S , s_row , s_col);   

    return 0;
}
