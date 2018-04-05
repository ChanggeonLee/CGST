#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node * left;
  struct node * right;
} Queue;

void enqueueFront(Queue * *queue,int item){
  Queue * Front , * temp , *cursor , *Rear;
  temp = (Queue*)malloc(sizeof(Queue));

  temp->data = item;
  temp->right = NULL;
  temp->left = NULL;

  if(*queue == NULL){
    //첫입력
    (*queue) = temp;

  }else{

    temp->right = *queue;
    (*queue)->left = temp;
    (*queue) = temp;

  }

  Front = *queue;
  for( cursor = *queue ; cursor->right != NULL ; cursor = cursor->right );
  Rear = cursor;

}

void enqueueRear(Queue * *queue, int item){
  Queue * temp , * Front , * Rear ,*cursor;

  temp = (Queue*)malloc(sizeof(Queue));

  temp->data = item;
  temp->right = NULL;
  temp->left = NULL;

  if(*queue == NULL){
    //첫입력
    (*queue) = temp;

  }else{

    Front = *queue;
    for( cursor = *queue ; cursor->right != NULL ; cursor = cursor->right );
    Rear = cursor;

    Rear->right = temp;
    temp->left = Rear;
    Rear = temp;

  }

}

void dequeueFront(Queue * *queue){
  Queue * temp , * Front , * Rear ,*cursor;
  Front = *queue;

  Front  = Front->right;
  *queue = Front;

}

void dequeueRear(Queue * *queue){
  Queue * temp , * Front , * Rear ,*cursor;
  for( cursor = *queue ; cursor->right != NULL ; cursor = cursor->right );
  Rear = cursor;

  Rear = Rear->left;
  Rear->right = NULL;

}

void Print(Queue *queue){
  Queue * cursor;

  for(cursor = queue;cursor != NULL; cursor = cursor->right){
    printf("%d -> ",cursor->data);
  }
  printf("END\n");

}

int main(){
  Queue * queue = NULL;
  Queue * cursor;
  enqueueRear(&queue,1);
  enqueueRear(&queue,2);
  enqueueRear(&queue,3);
  enqueueRear(&queue,4);
  enqueueRear(&queue,5);

  dequeueFront(&queue);
  dequeueFront(&queue);

  Print(queue);

  return 0;
}
