#include <stdio.h>
#define MAX 10

int Linear_Search(int x[MAX], int key){
  int i;
  for(i = 0 ; i < MAX ; i++){
    printf("인덱스 조사 = %d\n",i);
    if(x[i] == key){
      return i;
    }
  }
  return -1;
}


int main(){
  int a[MAX] = {1,2,10,9,3,4,8,5,6,7};
  int want;
  int out;

  scanf("%d",&want);

  out = Linear_Search(a,want);

  if(out != -1){
    printf("탐색 결과 = %d\n",a[out]);
  }else{
    printf("탐색 실패\n");
  }

  return 0;
}
