#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct item {
   int data;
   struct item *next;
};
// insert 함수는 크기순서에 맞게 적절한 위치에 삽입하는 함수.
// 작은 수가 가장 앞에 있도록 한다. 
void insert(struct item **ppS, int num) {
   struct item *tmp;
   struct item *p ;
   tmp = (struct item *)malloc(sizeof(struct item));
   tmp->data = num;
   tmp->next = NULL;
   
   // 처음 입력일때
   if ( *ppS == NULL) {
      *ppS = tmp;
   }else{
       // 중간부에 삽입 
       for (p = *ppS ; p != NULL; p = p->next) {
          // num값이 
          // 중간에 삽입 하는 경우
          if(p->next != NULL && p->next->data > num  ){
            tmp->next = p->next;
            p->next = tmp;
            break;
          }else if(p->next == NULL){
            p->next = tmp;
            break;
          }
       } 
   }
   
   return ;
}

// 확인을 위해 전부를 순서대로 출력해보는 함수 printall
void print_all(struct item * pS) {   // 이때는 * 가 하나만 있음 된다.
   while (pS != NULL) {
      printf("%d-->", pS->data);
      pS = pS->next;
   }
   printf("END\n");
}

int main() {
   struct item *pStart = 0;
   int data;
   pStart = NULL;

   while (scanf("%d", &data) == 1) {
      insert(&pStart, data);
   }
   print_all(pStart);

   return 0;
}
