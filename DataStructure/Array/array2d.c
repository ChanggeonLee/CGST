#include <stdio.h>
int main(){
  int a[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25} ;
  int L , R ;
  int Pnum = 0 ;

  for(int i = 0 ; i < 9 ; i++){

    if(i <= 4){

      Pnum ++ ;
      L = i ;
      R = 0 ;

    }else{

      Pnum -- ;
      L = 4 ;
      R = i - 4 ;

    }

    for(int k = 0 ; k < Pnum ; k++){
        printf("%d  " , a[L][R]) ;

        L-- ;
        R++ ;

    }

  }

  printf("\n");

  return 0 ;
}
