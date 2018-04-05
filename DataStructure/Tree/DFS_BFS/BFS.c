#include <stdio.h>
#define NODE 7
#define EMPTY -1
int rear  = -1;
int front = -1;
int Visit[NODE] = {0};

typedef struct city{
  int data; //
  int distance; // 시작점과의 거리
}City;

City Queue[NODE];

void EnQueue(int,char);
int DeQueue();

int main(){
  int distance = 0;
  int j , node;
  char find_city;
  // make grape
  int Graph [NODE][NODE] = { {0,1,1,0,0,0,0},
                             {0,0,0,0,0,1,1},
                             {1,0,0,1,1,0,0},
                             {0,0,1,0,1,1,0},
                             {0,0,1,1,0,0,0},
                             {0,1,0,1,0,0,1},
                             {0,1,0,0,0,1,0}
                           };


  printf("찾고자 하는 도시를 입력하세요:");
  scanf("%c",&find_city);

  EnQueue(0 , find_city); // Start node push!

  while(1)
  {

      node = DeQueue();

      if(node == EMPTY)
        break;

      for(j=0;j<NODE;j++)
      {
          if(Graph[node][j] && (!Visit[j]))
            EnQueue(j,find_city);
      }

  }

  return 0;
}

void EnQueue(int j , char find_city)
{
    if(!(rear>NODE))
    {

        Visit[j]=1;
        //printf("%c - ",j+'A');

        rear++;
        Queue[rear].data = j;

        if(rear-1 == -1){
          Queue[rear].distance = 0;
        }else if(front == -1){
          Queue[rear].distance = Queue[front].distance + 2;
        }else {
          Queue[rear].distance = Queue[front].distance + 1;
        }

        //printf("%d\n",Queue[rear].distance);

        if(find_city == j+'A'){
          printf("A에서  %c까지 덜어진 거리는 %d 입니다.\n", j+'A', Queue[rear].distance);
        }

    }
}

int DeQueue()
{
    front++;
    if(front <= rear)
      return Queue[front].data;
    else
      return EMPTY;
}
