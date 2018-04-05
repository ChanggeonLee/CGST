#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * left;
  struct node * right;
};

void AddNode( struct node * *h , int num ){
  struct node * cursor , *temp;

  temp  = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  temp->left = NULL;
  temp->right = NULL;

  if( *h == NULL ){

    *h = temp;

  }else{

    for(cursor = *h ; cursor->right != NULL ; cursor = cursor->right);
    cursor->right = temp;
    temp->left = cursor;

  }

  return ;
}

void PrintNode( struct node *h ){
  struct node * cursor;

  for(cursor = h ; cursor != NULL ; cursor = cursor->right){
    printf("%d  ",cursor->data);
  }
  printf("\n");

  return ;
}

void InsertNode( struct node * *h , int num){

  struct node * temp , *cursor , * cursor2 , *tail;
  for(cursor = *h ; cursor->right != NULL ; cursor = cursor->right);
  tail = cursor;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  temp->right = NULL;
  temp->left = NULL;
  for(cursor = *h ; cursor->data <= temp->data && cursor->right != NULL ; cursor = cursor->right);

  if(cursor == *h){

    temp->right = cursor;
    cursor->left = temp;
    *h = temp;

  }else if(cursor == tail){

    cursor->right = temp;
    temp->left = cursor;
    tail = temp;

  }else{

    for(cursor2 = *h ; cursor2->right != cursor && cursor2->right != NULL ; cursor2 = cursor2->right);
    temp->right = cursor;
    cursor->left = temp;
    cursor2->right = temp;
    temp->left = cursor2;

  }

  return;
}

void DelNode( struct node * *h , int num){
  struct node * temp , *cursor , * cursor2 , *cursor3 , *tail;
  for(cursor = *h ; cursor->right != NULL ; cursor = cursor->right);
  tail = cursor;

  for(cursor = *h ; cursor->data != num && cursor->right != NULL ; cursor = cursor->right);

  if(cursor == *h){

    *h = cursor->right;
    cursor->right = NULL;

  }else if(cursor == tail){

    for(cursor2 = *h ; cursor2->right != cursor && cursor2->right != NULL ; cursor2 = cursor2->right);
    cursor2->right = NULL;
    tail = cursor2;

  }else{

    for(cursor2 = *h ; cursor2->right != cursor && cursor2->right != NULL ; cursor2 = cursor2->right);
    for(cursor3 = tail ; cursor3->left != cursor && cursor3->left != NULL ; cursor3 = cursor3->left);
    cursor2->right = cursor3;
    cursor3->left = cursor2;

  }

  return ;
}

int main() {
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
