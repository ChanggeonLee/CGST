#include <stdio.h>
int main(){
  int a[10] = {8,17,5,18,5,9,1,2,5,4};
  int *p = &a[0];
  int *point = &a[0];


//짝수의 개수
  int num = 0 ;// 짝수의 개수를 저장하기 위한 변수

  for(int i = 0 ; i < 10 ; i++){
      if(*p%2 == 0 ){
        num++;
      }
      p++;
    }

    printf("짝수의 개수는 %d개 입니다.\n",num);

    p = &a[0];

//같은 수가 반복되는지 확인하는
  point++;
  for(int i = 0 ; i < 10 ; i++){

    for(int k = 1 ; k < 10 ; k++){

      if(*p == *point){
        printf("%d는 같은 수가 반복된다.\n!",*p);
      }

      point++;

    }

    p++;
    point = p+1;


  }

  p = &a[0];

//최대값과 최소값 차이
int min = 0 ;//최솟값
int max = 0 ;//최댓값
int dif;//차이

//최댓값을 구하는 부분
  max = *p;
  for(int i = 0 ; i < 9 ; i++){

    p++;
    int temp = *p;

    if(max <= temp){
      max = temp;
    }

  }

  p = &a[0];

//최솟값을 구하는 부분
  min = *p;
  for(int i = 0 ; i < 9 ; i++){

    p++;
    int temp = *p;

    if(min >= temp){
      min = temp;
    }

  }

  dif = max - min ;

  printf("최댓값은 %d입니다\n",max);
  printf("최솟값은 %d입니다\n",min);
  printf("최댓값과 최솟값의 차이는 %d입니다\n",dif);

  return 0;
}
