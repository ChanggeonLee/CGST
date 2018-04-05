#include <stdio.h>
#include <string.h>
#define MAX 10

int Stack_Array[ MAX ] = {};
int top = -1;

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
  


  return 0;
}
