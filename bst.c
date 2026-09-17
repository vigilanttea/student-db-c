#include"students.h"
#include"bst.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//bst funtions

void Insert_BST(BSTNode** root, Student data){
    
    if(*root==NULL){
         BSTNode* NewStud=malloc(sizeof(BSTNode));
         NewStud->data.id=data.id;
         NewStud->data.gpa=data.gpa;
         NewStud->data.level=data.level;
         strcpy(NewStud->data.name,data.name);
         *root=NewStud;
        return;
    }

    if((*root)->data.id>data.id) Insert_BST(&(*root)->left,data);
    if((*root)->data.id<data.id) Insert_BST(&(*root)->right,data);
    return;
}

void Display_BST(BSTNode* root){
    if(root==NULL) return;

    Display_BST(root->left);

    printf("================\n ID: %d\n Name:%s\n GPA:%f\n Level:%d\n",
        root->data.id,root->data.name,root->data.gpa,root->data.level);
    
    Display_BST(root->right);
}

BSTNode* Find_Min(BSTNode* root){
    if(root==NULL||root->left==NULL) return root;
    return Find_Min(root->left);
}


int Delete_BST(BSTNode** root, int id){
    if(*root==NULL) return -1;
    
    if((*root)->data.id>id)  return Delete_BST(&(*root)->left,id);

    else if((*root)->data.id<id) return Delete_BST(&(*root)->right,id);

    else{
        BSTNode* temp=*root;
        if((*root)->left==NULL||(*root)->right==NULL){
            *root=(*root)->left?(*root)->left:(*root)->right;
            free(temp);
            return 0;
        }

        BSTNode* succ=Find_Min((*root)->right);
        (*root)->data=succ->data;
        return Delete_BST(&(*root)->right,succ->data.id);
    }
    return 1;
}

BSTNode* Search_BST(BSTNode* root,int id){
    if(root==NULL) return NULL;
    if(root->data.id>id) return Search_BST(root->left,id);
    else if(root->data.id<id) return Search_BST(root->right,id);
    else return root;
}


int Update_BST(BSTNode* root,int id,float gpa, char name[MAX_NAME],int level){
   BSTNode* temp=Search_BST(root,id);
   if(temp==NULL) return 1;
   temp->data.gpa=gpa;
   temp->data.level=level;
   strcpy(temp->data.name,name);
   return 0;
}

void Free_BST(BSTNode** root){
     if(*root==NULL){
        return;
    }
    Free_BST(&(*root)->left);
    Free_BST(&(*root)->right);

    free(*root);
    *root=NULL;
}