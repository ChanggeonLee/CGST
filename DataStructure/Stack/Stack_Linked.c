#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * next;
};

struct node * Stack_Link = NULL;
struct node * top;

void push(int item){

  struct node * temp;

  temp = (struct node*)malloc(sizeof(struct node));

  temp->data = item;
  temp->next = NULL;

  if( Stack_Link == NULL ){

    Stack_Link = temp;

  }else{

    temp->next = Stack_Link;
    Stack_Link = temp;

  }

  top = Stack_Link;

}

int pop(){
  int p;

  p = top->data;

  if(top->next == NULL){
    Stack_Link = NULL;
  }else{
    Stack_Link = Stack_Link->next;
  }

  top = Stack_Link;

  return p;
}

void Print(){
  struct node * cursor;
  for(cursor = top ; cursor != NULL; cursor = cursor->next){
    printf("%d -> ",cursor->data);
  }
  printf("END\n");
}

int main(){

  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  printf("pop => %d \n",pop());
  printf("pop => %d \n",pop());
  printf("pop => %d \n",pop());

  Print();
  return 0;
}
