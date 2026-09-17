#include"students.h"
#include"linked_list.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//students linked list

void Add_LL(LLNode** head, Student data){
    LLNode* NewStud=malloc(sizeof(LLNode));
    NewStud->data.id=data.id;
    NewStud->data.gpa=data.gpa;
    NewStud->data.level=data.level;
    strcpy(NewStud->data.name,data.name);
    NewStud->next=NULL;

    if(*head==NULL){
        *head=NewStud;
        return;
    }

    NewStud->next=*head;
    *head=NewStud;
    return;
}

int Delete_LL(LLNode** head, int id){
    if(*head==NULL) return -1;
    
    LLNode* cur=*head;
    if((*head)->data.id==id){
        *head=(*head)->next;
        free(cur);
        return 0;
    }
    LLNode* prev=cur;

    while (cur!=NULL){
        if(cur->data.id==id){
            prev->next=cur->next;
            free(cur);
            return 0;
        }
       prev=cur;
       cur=cur->next;
    }

}

LLNode* Search_LL(LLNode* head,int id){
    if(head==NULL){
        return NULL;
    }

    LLNode* cur=head;

    while (cur!=NULL){
        if(cur->data.id==id){
            return cur;
        }
       cur=cur->next;
    }
    return NULL;
}

void Display_LL(LLNode* head){
    if(head==NULL) return;
    printf("================\n ID: %d\n Name:%s\n GPA:%f\n Level:%d\n",
        head->data.id,head->data.name,head->data.gpa,head->data.level);
    Display_LL(head->next);
}

int count(LLNode* head){
    if(head==NULL) return 0;
    int count=0;
    for(LLNode* cur=head;cur!=NULL;cur=cur->next) count++;
    return count;
}

void Update_LL(LLNode* Stud, char name[MAX_NAME], float gpa, int level){ 
    Stud->data.gpa=gpa;
    Stud->data.level=level;
    strcpy(Stud->data.name,name);
    return;
}


void Free_LL(LLNode** head){
     LLNode* temp;
    while(*head!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}