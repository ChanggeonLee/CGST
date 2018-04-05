#include <stdio.h>
#include <stdbool.h>
#define NODE 7
int Stack[NODE] = {0};
int Visit[NODE];
int top = -1;

void Push(int);
void Pop();

int main(){
  int j;
  bool cycle = false;
  // make grape
  int Graph [NODE][NODE] = { {0,1,1,0,0,0,0},
                             {0,0,0,0,0,1,1},
                             {1,0,0,1,1,0,0},
                             {0,0,1,0,1,1,0},
                             {0,0,1,1,0,0,0},
                             {0,1,0,1,0,0,1},
                             {0,1,0,0,0,1,0}
                           };
  Push(0); // Start node push!
  while(top >= 0)
  {
      for(j=0; j<NODE ; j++)
      {
        if(Graph[Stack[top]][j])
        {
          if((!Visit[j]))
          {
            // j=0;
            Push(j);
            j=0;
          }else
          {
            cycle = true;
          }
        }
      }
      Pop();
  }

  if(cycle){
    printf("사이클이 존재합니다\n");
  }else{
    printf("사이클이 존재하지 않습니다\n");
  }

  return 0;
}

void Push(int j)
{
  if( !(top > NODE) )
  {
      Visit[j] = 1;
      printf("%c\n",j+'A');

      top++;
      Stack[top] = j;
  }
}

void Pop()
{
  if(top >= 0 )
    top--;
}
