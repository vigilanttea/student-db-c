#ifndef LL_H
#define LL_H
#include"students.h"

typedef struct LLNode{
    Student data;
    struct LLNode* next;
}LLNode;

void Add_LL(LLNode** head, Student data);

int Delete_LL(LLNode** head, int id);

LLNode* Search_LL(LLNode* head,int id);

void Display_LL(LLNode* head);

void Update_LL(LLNode* Stud, char name[MAX_NAME], float gpa, int level);

int Count_Students(LLNode* head);

void Free_LL(LLNode** head);

#endif