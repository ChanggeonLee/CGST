#include <stdio.h>

void findAncestor(int tree[11],int find){
  int i;
  for(i = 1 ; i <= 10 && tree[i] != find; i++ );
  printf("%d의 조상은\n",find);
  while(i > 1 ){
    i = i/2;
    printf("%d\n", tree[i]);
  }
}

void findChildren_right(int tree[11],int find){
  int i;
  for(i = 1 ; i <= 10 && tree[i] != find; i++ );
  printf("%d의 오른쪽 자식은\n",find);
  while(2 * i + 1 <= 11 ){
    i = i * 2 + 1;
    printf("%d\n", tree[i]);
  }
}

void findChildren_left(int tree[11],int find){
  int i;
  for(i = 1 ; i <= 10 && tree[i] != find; i++ );
  printf("%d의 왼쪽 자식은\n",find);
  while(2 * i <= 11 ){
    i = i * 2 ;
    printf("%d\n", tree[i]);
  }
}

int main(){
  int tree[11] = {10 ,1,2,3,4,5,6,7,8,9,10 };
  int find;


  printf("조상을 찾고 싶은 인덱스를 입력하세요 : ");
  scanf("%d" ,&find );

  findAncestor(tree,find);
  findChildren_left(tree,find);
  findChildren_right(tree,find);

}
