#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode{
  int data;
  struct treeNode * left;
  struct treeNode * right;
}treeNode ;

void make_tree(treeNode * *r){
  treeNode  *temp , *left_subtree , * right_subtree;


    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 0;
    temp -> left = NULL;
    temp -> right = NULL;

    (*r) = temp;

    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 2;
    temp -> left = NULL;
    temp -> right = NULL;

    (*r)-> left = temp;

    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 3;
    temp -> left = NULL;
    temp -> right = NULL;

    (*r)->right = temp;

    left_subtree = (*r)->left;

    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 4;
    temp -> left = NULL;
    temp -> right = NULL;

    left_subtree->left = temp;

    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 5;
    temp -> left = NULL;
    temp -> right = NULL;

    left_subtree->right = temp;

    right_subtree = (*r)->right;

    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = 6;
    temp -> left = NULL;
    temp -> right = NULL;

    right_subtree ->left = temp;

}

void inorder_traversal(treeNode * root){
  if(root != NULL){
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main(){
  treeNode * root;
  make_tree(&root);
  inorder_traversal(root);

}
