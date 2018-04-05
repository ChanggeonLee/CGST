#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node * next;
};

int main(){
  struct node * head , *temp , *cursor;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = 3;
  temp->next = NULL;
  head = temp;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = -1;
  temp->next = NULL;
  for(cursor = head ; cursor->next != NULL ; cursor = cursor->next);
  cursor->next = temp;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = 100;
  temp->next = NULL;
  for(cursor = head ; cursor->next != NULL ; cursor = cursor->next);
  cursor->next = temp;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = 99;
  temp->next = NULL;
  for(cursor = head ; cursor->next != NULL ; cursor = cursor->next);
  cursor->next = temp;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = 8;
  temp->next = NULL;
  for(cursor = head ; cursor->next != NULL ; cursor = cursor->next);
  cursor->next = temp;

  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = 0;
  temp->next = NULL;
  for(cursor = head ; cursor->next != NULL ; cursor = cursor->next);
  cursor->next = temp;

  for(cursor = head ; cursor != NULL ; cursor = cursor->next){
    printf("%d  " , cursor->data);
  }
  printf("\n");

  int min , max;
  max = head->data;
  for(cursor = head ; cursor != NULL ; cursor = cursor->next){
    if(max <= cursor->data){
      max = cursor->data;
    }
  }

  min = head->data;
  for(cursor = head ; cursor != NULL ; cursor = cursor->next){
    if(min >= cursor->data){
      min = cursor->data;
    }
  }

  printf("max = %d\nmin = %d\n" , max , min);

}
