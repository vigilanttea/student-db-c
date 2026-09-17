#ifndef BST_H
#define BST_H
#include"students.h"

typedef struct BSTNode{
    Student data;
    struct BSTNode* left;
    struct BSTNode* right;
}BSTNode;

void Insert_BST(BSTNode** root, Student data);

void Display_BST(BSTNode* root);

int Delete_BST(BSTNode** root, int id);

BSTNode* Find_Min(BSTNode* root);

BSTNode* Search_BST(BSTNode* root,int id);

int Update_BST(BSTNode* root,int id,float gpa, char name[MAX_NAME],int level);

void Free_BST(BSTNode** root);

#endif