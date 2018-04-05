#include <stdio.h>
#define MAX 10

int Stack_Array[ MAX ] = {};
int top = -1;

void isFULL(){

  if( top == MAX ){
    printf("Stack이 꽉 차 있습니다.\n");
  }else{
    printf("Stack이 꽉 차 있습니다.\n");
  }

}

void isEmpty(){

  if( top == -1 ){
    //비어있음
    printf("Stack이 비어있습니다.\n");
  }else{
    printf("Stack이 차있습니다.\n");
  }

}

void push( int item ){
  Stack_Array[++top] = item;
}

int pop(){
  int p;

  p = Stack_Array[top];
  Stack_Array[top] = 0;
  top-- ;

  return p;
}

int main(){

  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  push(7);
  push(8);
  push(9);
  push(10);

  isFULL();

  for(int i = top ;i >= 0 ; i--){
    printf("%d " , pop());
  }
  printf("\n");

  isEmpty();

  return 0;
}
