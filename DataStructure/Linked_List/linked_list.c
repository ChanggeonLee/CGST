#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void AddNode( struct node * *h , int num ){
  struct node * temp , *cursor;
  //처음 입력
  temp = (struct node *) malloc(sizeof(struct node));
  temp->data = num;
  temp->next = NULL;

  if( *h == NULL ){

    //첫입력
    *h = temp;

  }else{

    //두번째 입력부터
    for(cursor = *h ; cursor->next != NULL ; cursor = cursor->next);
    cursor->next = temp;

  }

  return ;
}

void PrintNode(struct node * h ){
  struct node  *cursor;

  // 출력
  for( cursor = h ; cursor != NULL ; cursor = cursor->next ){
    printf( " %d ", cursor->data );
  }
  printf("\n");

  return ;
}

void InsertNode( struct node * *h, int num ){
  struct node * temp , *cursor , *cursor2;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  temp->next = NULL;
  for(cursor = *h ; cursor->data <= temp->data && cursor->next != NULL ; cursor = cursor->next );

  if(cursor == *h){

    // (1)
    temp->next = *h;
    *h = temp;

  }else if(cursor->next == NULL){

    // (2)
      cursor->next = temp;

  }else{

    // (3)
    for(cursor2 = *h ; cursor2->next != cursor && cursor->next != NULL ; cursor2 = cursor2->next );
    temp->next = cursor;
    cursor2->next = temp;

  }

  return ;

}

void DelNode( struct node * *h, int num){

  struct node *cursor , *cursor2  ;
  for(cursor = *h ; cursor->data != num && cursor->next != NULL ; cursor = cursor->next);

  if(cursor == *h){
    //(1)
    *h = cursor->next;
    cursor->next = NULL;

  }else if(cursor->next == NULL){

    //(2)
    for(cursor2 = *h ; cursor2->next != cursor && cursor2->next != NULL ; cursor2 = cursor2->next );
    cursor2->next = NULL;

  }else{

    //(3)
    for(cursor2 = *h ; cursor2->next != cursor && cursor2->next != NULL ; cursor2 = cursor2->next );
    cursor2->next = cursor->next;
    cursor = NULL;

  }

  return ;

}

int main(){
  struct node *head = NULL;

  AddNode( &head , 1 );
  AddNode( &head , 3 );
  AddNode( &head , 5 );
  AddNode( &head , 7 );

  //출력
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
