#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode{
  int data;
  struct treeNode * left;
  struct treeNode * right;
}treeNode ;

treeNode* create_tree(int num){
  treeNode  *temp;

  temp = (treeNode *)malloc(sizeof(treeNode));
  temp -> data = num;
  temp -> left = NULL;
  temp -> right = NULL;

  return temp;

}

void insertTree(treeNode ** tree , treeNode * child){
    if((*tree)->data < child->data){
      if((*tree)->right == NULL){
        (*tree)->right = child;
      }else{
        insertTree(&(*tree)->right,child);
      }
    }else if((*tree)->data > child->data){
      if((*tree)->left == NULL){
        (*tree)->left = child;
      }else{
        insertTree(&(*tree)->left , child);
      }
    }
}

void make_tree(treeNode ** root , int num){
  if(*root == NULL){
    *root = create_tree(num);
  }else{
    insertTree(root,create_tree(num));
  }
}

treeNode* SearchBST(treeNode * BST , int find){
  treeNode *root = BST;

  if(root == NULL){
    return NULL;
  }else if(root->data == find){
    return root;
  }else if(root->data < find){
    return SearchBST(root->right,find);
  }else{
    return SearchBST(root->left,find);
  }

}

treeNode* Search_parent(treeNode * BST , treeNode * find , int num){
  treeNode *root = BST;

  if(root == NULL){
    return NULL;
  }else if(root ->right == find){
    return root;
  }else if(root ->left == find){
    return root;
  }else if(root->data < num){
    return Search_parent(root->right,find , num);
  }else{
    return Search_parent(root->left,find , num);
  }

}

treeNode* maxNode(treeNode * root){
  if(root->right == NULL){
    return root;
  }else{
    return maxNode(root->right);
  }
}

void DeleteBST(treeNode * root , int find){
  treeNode * delete , *parent;
  delete = SearchBST(root,find);
  parent = Search_parent(root,delete,find);

  if(delete == NULL){
    return ;
  }

  if(delete->left == NULL && delete->right == NULL){
    //자식이없을때
    printf("자식이 없을때\n");
    if(parent->left == delete){
      parent->left = NULL;
    }else{
      parent->right = NULL;
    }

  }else if(delete->left == NULL && delete->right != NULL){
    //자식이 하나
    printf("삭제 차수1\n");
    if(parent->right == delete){
      parent->right = delete->right;
    }else{
      parent->left = delete->right;
    }
  }else if(delete->right == NULL && delete->left != NULL){
    //자식이 하나
    printf("삭제 차수1\n");
    if(parent->right == delete){
      parent->right = delete->left;
    }else{
      parent->left = delete->left;
    }
  }else{
    treeNode * succ_p , *succ;
    succ_p = delete;
    succ = delete->right;
    while(succ->left != NULL){
      succ_p = succ;
      succ = succ->left;
    }

    if(succ_p->left == succ){
      succ_p->left = succ->right;
    }else{
      succ_p->right = succ->right;
    }

    delete->data = succ->data;
    delete = succ;

  }

}

void inorder_traversal(treeNode * root){
  if(root != NULL){
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main(){
  treeNode * root = NULL;

  make_tree(&root,8);
  make_tree(&root,3);
  make_tree(&root,10);
  make_tree(&root,1);
  make_tree(&root,6);
  make_tree(&root,14);
  make_tree(&root,4);
  make_tree(&root,7);
  make_tree(&root,13);
  //make_tree(&root,15);
  int num;
  treeNode * find , *parent;
  printf("찾고싶은 수를 입력:");
  scanf("%d",&num);

  inorder_traversal(root);
  printf("\n");
  DeleteBST(root,num);
  inorder_traversal(root);
  printf("\n");
}
