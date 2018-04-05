#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node * next;

} Queue;

void enqueue(Queue * *queue , int item){
  Queue * temp , * Front , * Rear ,*cursor;

  temp = (Queue*)malloc(sizeof(Queue));

  temp->data = item;
  temp->next = NULL;

  if(*queue == NULL){
    //첫입력
    (*queue) = temp;

  }else{

    Front = *queue;
    for( cursor = *queue ; cursor->next != NULL ; cursor = cursor->next );
    Rear = cursor;

    Rear->next = temp;
    Rear = temp;
    
  }
}

int dequeue(Queue * *queue){

  Queue * Front;
  int out;
  Front = *queue;

  out = Front->data;

  Front  = Front->next;
  *queue = Front;

  return out;

}

void Print(Queue * queue){
  Queue * cursor;

  for(cursor = queue;cursor != NULL; cursor = cursor->next){
    printf("%d -> ",cursor->data);
  }
  printf("END\n");
}

int main(){
  Queue * queue = NULL;

  enqueue(&queue,1);
  enqueue(&queue,2);
  enqueue(&queue,3);
  enqueue(&queue,4);

  printf("%d \n",dequeue(&queue));
  printf("%d \n",dequeue(&queue));

  Print(queue);

  return 0;
}
