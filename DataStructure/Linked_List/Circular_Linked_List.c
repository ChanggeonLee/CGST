#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * next;
};

void AddNode( struct node * *h , int num){
  struct node *cursor , *temp;

  temp = (struct node *) malloc(sizeof(struct node));
  temp->data = num;
  temp->next = NULL;

  if( *h == NULL ){

    *h = temp;
    temp->next = *h;

  }else{

    for(cursor = *h ; cursor->next != *h ; cursor = cursor->next);
    cursor->next = temp;
    temp->next = *h;

  }

  return ;

}

void PrintNode( struct node * h){
  struct node * cursor;
  for( cursor = h ; cursor->next != h; cursor = cursor->next ){
    printf( " %d ", cursor->data );
  }
  printf( " %d ", cursor->data );
  printf("\n");

  return ;
}

void InsertNode( struct node * *h , int num ){
  struct node *cursor , *temp , * cursor2 ;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  temp->next = NULL;
  for(cursor = *h ; cursor->data <= temp->data && cursor ->next != *h ; cursor = cursor->next);

  if(cursor == *h){

    //시작
    for(cursor2 = *h ; cursor2->next != *h ; cursor2 = cursor2->next);
    temp->next = cursor;
    *h = temp;
    cursor2->next = *h;

  }else if(cursor->next == *h){

    //끝
    temp->next = cursor->next;
    cursor->next = temp;

  }else{

    //중간
    for(cursor2 = *h ; cursor2->next != cursor && cursor->next != *h ; cursor2 = cursor2->next );
    temp->next = cursor;
    cursor2->next = temp;

  }

  return ;
}

void DelNode( struct node * *h , int num ){
  struct node *cursor , *temp , * cursor2 , *tail;

  for(tail = *h ; tail->next != *h ; tail = tail->next);

  for(cursor = *h ; cursor->data != num ; cursor = cursor->next);

  if(cursor == *h){

    //처음
    *h = cursor->next;
    tail->next = *h;

  }else if(cursor->next == *h){

    //끝
    for(cursor2 = *h ; cursor2->next != cursor ; cursor2 = cursor2->next);
    cursor2->next = *h;
    tail = cursor2;

  }else{

    //중간
    for(cursor2 = *h ; cursor2->next != cursor ; cursor2 = cursor2->next);
    cursor2->next = cursor->next;

  }

  return ;
}

int main(){
  struct node * head = NULL ;

  AddNode( &head , 1 );
  AddNode( &head , 3 );
  AddNode( &head , 5 );
  AddNode( &head , 7 );

  PrintNode(head);

  InsertNode( &head , 0 );
  InsertNode( &head , 4 );
  InsertNode( &head , 8 );

  PrintNode(head);

  DelNode( &head , 0 );
  DelNode( &head , 4 );
  DelNode( &head , 8 );

  PrintNode(head);

  return 0;
}
