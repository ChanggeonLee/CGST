#include <stdio.h>
#include <stdlib.h>
struct Graph{
  char node ;
  int distance;
  struct Graph * next_node;
};

struct Graph * Node1 = NULL;
struct Graph * Node2 = NULL;
struct Graph * Node3 = NULL;
struct Graph * Node4 = NULL;
struct Graph * Node5 = NULL;

struct Graph* makeNode(char node , int distance){
  struct Graph * temp;

  temp = (struct Graph*)malloc(sizeof(struct Graph));
  temp->node = node;
  temp->distance = distance ;
  temp->next_node = NULL;

  return temp;
}

void creatGraph(){
  struct Graph * cursor ;

  Node1 = makeNode('A',0);

  for(cursor = Node1 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('B',4);

  for(cursor = Node1 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('C',2);

  Node2 = makeNode('B',0);

  for(cursor = Node2 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('D',1);

  for(cursor = Node2 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('E',2);

  Node3 = makeNode('C',0);

  for(cursor = Node3 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('D',1);

  Node4 = makeNode('D',5);

  for(cursor = Node4 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('A',3);

  for(cursor = Node4 ; cursor->next_node != NULL ; cursor = cursor->next_node);
  cursor->next_node = makeNode('E',4);

  Node5 = makeNode('E',0);

}

void print(){
  struct Graph * cursor ;

  for(cursor = Node1 ; cursor != NULL ; cursor = cursor->next_node){
    printf("NODE : %c \n" ,cursor->node);
    printf("%c -> %c 의 거리 : %d\n",Node1->node , cursor->node , cursor->distance);
  }
  printf("=========================\n");

  for(cursor = Node2 ; cursor != NULL ; cursor = cursor->next_node){
    printf("NODE : %c \n" ,cursor->node);
    printf("%c -> %c 의 거리 : %d\n",Node2->node , cursor->node , cursor->distance);
  }
  printf("=========================\n");

  for(cursor = Node3 ; cursor != NULL ; cursor = cursor->next_node){
    printf("NODE : %c \n" ,cursor->node);
    printf("%c -> %c 의 거리 : %d\n",Node3->node , cursor->node , cursor->distance);
  }
  printf("=========================\n");

  for(cursor = Node4 ; cursor != NULL ; cursor = cursor->next_node){
    printf("NODE : %c \n" ,cursor->node);
    printf("%c -> %c 의 거리 : %d\n",Node4->node , cursor->node , cursor->distance);
  }
  printf("=========================\n");

  for(cursor = Node5 ; cursor != NULL ; cursor = cursor->next_node){
    printf("NODE : %c \n" ,cursor->node);
    printf("%c -> %c 의 거리 : %d\n",Node5->node , cursor->node , cursor->distance);
  }
  printf("=========================\n");

}

void Find_Edge(char Node){
    struct Graph * cursor;

    printf("node %c의 edge\n" , Node);

    if(Node == Node1->node){

      printf("NODE : %c \n" , Node1->node);
      for(cursor = Node1 ; cursor != NULL ; cursor = cursor->next_node){
        printf("%c -> %c 의 거리 : %d\n",Node1->node , cursor->node , cursor->distance);
      }

    }else if(Node == Node2->node){

      printf("NODE : %c \n" ,Node2->node);
      for(cursor = Node2 ; cursor != NULL ; cursor = cursor->next_node){
        printf("%c -> %c 의 거리 : %d\n",Node2->node , cursor->node , cursor->distance);
      }

    }else if(Node == Node3->node){

      printf("NODE : %c \n" ,Node3->node);
      for(cursor = Node3 ; cursor != NULL ; cursor = cursor->next_node){
        printf("%c -> %c 의 거리 : %d\n",Node3->node , cursor->node , cursor->distance);
      }

    }else if(Node == Node4->node){

      printf("NODE : %c \n" ,Node4->node);
      for(cursor = Node4 ; cursor != NULL ; cursor = cursor->next_node){
        printf("%c -> %c 의 거리 : %d\n",Node4->node , cursor->node , cursor->distance);
      }

    }else if(Node == Node5->node){

      printf("NODE : %c \n" ,Node5->node);
      for(cursor = Node5 ; cursor != NULL ; cursor = cursor->next_node){
        printf("%c -> %c 의 거리 : %d\n",Node5->node , cursor->node , cursor->distance);
      }

    }

    printf("\n");

}

int main(){

  creatGraph();

  //print();

  Find_Edge('A');
  Find_Edge('B');
  Find_Edge('C');
  Find_Edge('D');
  Find_Edge('E');

  return 0;
}
