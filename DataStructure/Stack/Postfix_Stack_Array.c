#include <stdio.h>
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
  char c;
  int num1 , num2;

  while ( scanf("%c",&c) != -1 ){

    if(c != '\n' && c != '+' && c != '-' && c != '*' && c != '/'){
      //정수
      printf("정수 stack에 입력\n");
      c -= 48;
      push(c);

    }else if(c != '\n'){

      printf("계산\n");
      num1 = pop();
      num2 = pop();

      if(c == '+'){
        push(num1 + num2);
        printf("+결과 = %d\n" , num1+num2);
      }else if(c == '-'){
        push(num1 - num2);
        printf("-결과 = %d\n" , num1-num2);
      }else if(c == '*'){
        push(num1 * num2);
        printf("*결과 = %d\n" , num1*num2);
      }else if(c == '/'){
        push(num1 / num2);
        printf("/결과 = %d\n" , num2/num1);
      }

    }

  }

  printf( "답: %d \n ", pop() );


  return 0;
}
