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
    (*h)->left = temp;
    temp->right = *h;

  }else{

    for(cursor = *h ; cursor->right != *h ; cursor = cursor->right);
    cursor->right = temp;
    temp->left = cursor;
    (*h)->left = temp;
    temp->right = *h;

  }

  return ;
}

void PrintNode( struct node *h ){
  struct node * cursor;

  for(cursor = h ; cursor->right != h ; cursor = cursor->right){
    printf("%d  ",cursor->data);
  }
  printf("%d  ",cursor->data);
  printf("\n");

  return ;
}

void InsertNode( struct node * *h , int num){

  struct node * temp , *cursor , * cursor2 ;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = num;
  temp->right = NULL;
  temp->left = NULL;
  for(cursor = *h ; cursor->data <= temp->data && cursor->right != *h ; cursor = cursor->right);

  if(cursor == *h){

    for(cursor2 = *h ; cursor2->right != *h ; cursor2 = cursor2->right);
    temp->right = cursor;
    cursor->left = temp;
    temp->left = cursor2;
    cursor2->right = temp;
    *h = temp;

  }else if(cursor->right == *h){

    cursor->right = temp;
    temp->left = cursor;
    temp->right = *h;
    (*h)->left = temp;

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

  for(tail = *h ; tail->right != *h ; tail = tail->right);

  for(cursor = *h ; cursor->data != num ; cursor = cursor->right);

  if(cursor == *h){

    *h = cursor->right;
    tail->right = *h;
    (*h)->left = tail;

  }else if(cursor->right == *h){

    for(cursor2 = *h ; cursor2->right != cursor ; cursor2 = cursor2->right);
    cursor2->right = *h;
    tail = cursor2;
    (*h)->left = tail;

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
