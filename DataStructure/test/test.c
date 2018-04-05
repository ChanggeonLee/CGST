#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void Reverse(struct node * *h , struct node * *r){
  struct node *cursor , *cursor2 , *cursor3;

  if( *r == NULL ){
    for(cursor = *h ; cursor->next != NULL ; cursor = cursor->next);
    for(cursor2 = *h ; cursor2->next != cursor ; cursor2 = cursor2->next );
    *r = cursor;
    cursor2->next = NULL;
  }else if( (*h)->next == NULL ){
    for(cursor3 = *r ; cursor3->next != NULL ; cursor3 = cursor3->next);
    cursor3->next = *h;
    *h = NULL;
  }else{
    for(cursor = *h ; cursor->next != NULL ; cursor = cursor->next);
    for(cursor2 = *h ; cursor2->next != cursor ; cursor2 = cursor2->next );
    for(cursor3 = *r ; cursor3 ->next != NULL ; cursor3 = cursor3->next);
    cursor3->next = cursor;
    cursor2->next = NULL;
  }

}

void Addnode(struct node * *h, int num){
    struct node *temp , *cursor;
    if( *h == NULL ){

      temp = (struct node*)malloc(sizeof(struct node));
      temp->data = num; temp->next = NULL;
      *h = temp;

    }else{

      temp = (struct node*)malloc(sizeof(struct node));
      temp->data = num; temp->next = NULL;
      for(cursor = *h ; cursor->next != NULL ; cursor = cursor->next);
      cursor->next = temp;

    }
}

void Printnode(struct node *h){
  struct node * cursor;

  for(cursor = h ; cursor != NULL ; cursor = cursor->next){
    printf("%d -> ", cursor->data);
  }
  printf("END\n");

}

void testA1() {
  struct node *head , *temp , *cursor;

  Addnode( &head , 3);
  Addnode( &head , 10);
  Addnode( &head , 2);
  Addnode( &head , 1);
  Addnode( &head , 5);

  //출력
  Printnode( head );

  //뒤집어 준다.
  struct node * reverse = NULL;
  while( head != NULL ){
    Reverse( &head , &reverse);
  }

  head = reverse;

  //출력
  Printnode( head );

}

int main(){
  testA1();
  return 0;
}
