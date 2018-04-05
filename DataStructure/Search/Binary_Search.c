#include <stdio.h>
#define MAX 10

int Binary_Search(int x[MAX], int key){
  int front = 0;
  int mid;
  int tail = MAX-1;

  while(front <= tail){

    mid = ( front + tail ) / 2;

    if(x[mid] < key){
        front = mid + 1;
    }else if(x[mid] > key){
        tail = mid - 1;
    }else {
      return mid;
    }

    printf("mid = %d\n", mid);

  }

  return -1;

}


int main(){
  int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
  int want;
  int out;

  scanf("%d",&want);

  out = Binary_Search(a,want);

  if(out != -1){
    printf("탐색 결과 = %d\n",a[out]);
  }else{
    printf("탐색 실패\n");
  }

  return 0;
}
