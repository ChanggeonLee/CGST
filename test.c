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

struct node * sum( struct node * list1 , struct node * list2 ){
  struct node * new_list = NULL;

  while(list1 != NULL && list2 != NULL){
    int n;
    if(list1->data <= list2->data){
      // list1 data가 작을때
      n = list1->data;
      list1=list1->next;
    }else{  
      // list2 data가 작을때
      n = list2->data;
      list2=list2->next;
    }
    AddNode( &new_list , n); 
  }

  for(; list1 !=NULL ; list1 = list1->next){
    AddNode( &new_list , list1->data );
  }

  for(; list2 != NULL ; list2 = list2->next){
    AddNode( &new_list , list2->data );
  }
  return new_list;
}

int main(){
  struct node *list1 = NULL;
  struct node *list2 = NULL;
  struct node *new = NULL;
  AddNode( &list1 , 3);
  AddNode( &list1 , 5);
  AddNode( &list1 , 10);
  AddNode( &list1 , 21);

  AddNode( &list2 , 4);
  AddNode( &list2 , 6);
  AddNode( &list2 , 10);
  
  PrintNode(list1);
  PrintNode(list2);

  new = sum(list1 , list2);

  PrintNode(new);

  return 0;
}

