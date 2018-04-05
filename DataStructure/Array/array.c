#include <stdio.h>

int main(){
  int row;
  int col;
  int r ;
  int c ;
  int num;
  int a[row][col];

  scanf("%d%d",&row , &col);

  printf("정수 입력\n");
  for(c = 0 ; c < col ; c++){
    for(r = 0 ; r < row ; r++){
      scanf("%d", &num);
      a[r][c] = num;
    }
  }


  for(c = 0 ; c < col ; c++){
    for(r = 0 ; r < row ; r++){
      printf("%d ",a[r][c]);
    }
    printf("\n");
  }
  return 0;
}
