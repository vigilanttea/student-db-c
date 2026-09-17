#include<stdio.h>
#include<stdlib.h>
#include"students.h"
#include"linked_list.h"
#include"bst.h"

Student Create_student(){
  Student NewStud;
  printf("Enter ID, name, GPA, and level of student respectively\n");
  scanf("%d %s %f %d",&NewStud.id,NewStud.name,&NewStud.gpa,&NewStud.level);
  return NewStud;
}

void Print_Stud_Info(Student* data){
    printf("--------------INFO--------------\n");
    printf("ID: %d, Name: %s, GPA: %f, Level: %d\n",data->id,data->name,data->gpa,data->level);
}

void Print_Menu(){
    printf("\n=============Menu=============\n");
    printf("\n1. Add new student\n2. Search student\n3. Display all students\n4. Delete student\n5. Update Record\n6. Exit\n");
}

void Actions(int choice,BSTNode** root, LLNode** head){
    switch (choice)
    {
    case 1:{
        printf("\n-----------ADD NEW STUDENT----------\n");
        Student NewStud=Create_student();
        if(Search_BST(*root,NewStud.id)!=NULL){
            printf("!ID TAKEN\n");
            break;
        }
        Insert_BST(root, NewStud );
        Add_LL(head, NewStud);
        printf("\nINSERTED SUCCESS\n");
        break;
    }
    case 2:{
        printf("\n---------SEARCH------------\n");
        int id;
        printf("Enter the id of the student\n");
        scanf("%d",&id);
        LLNode* temp1=Search_LL(*head,id);
        if(temp1!=NULL) Print_Stud_Info(&(temp1)->data);
        else printf("NOT FOUND\n");
        break;
    }
    case 3:{
        printf("-----------DISPLAY ALL STUDENTS----------");
        printf("\n---------From BST-----------------\n");
        Display_BST(*root);
        printf("----------From LL--------------\n");
        Display_LL(*head);
        break;
    }
    case 4:{
        int id;
        printf("-----------DELETE STUDENT------------'\n");
        printf("Enter id:\n");
        scanf("%d",&id);
        if(Delete_BST(root,id)==0) printf("Deleted from BST\n");
        if(Delete_LL(head,id)==0) printf("Deleted from LL\n");
        break;
    }
    case 5:{
        int id;
        printf("--------------UPDATE RECORD------------------\n");
        printf("Enter ID\n");
        scanf("%d",&id);
        LLNode* temp=Search_LL(*head,id);
        if(temp==NULL){
            printf("NOT FOUND");
            break;
        }
        Print_Stud_Info(&(temp)->data);
        printf("\nEnter New GPA, new Level, new name repectively.\n!Incase old data is not to be changed still input the old one\n");
        float gpa; int level; char name[MAX_NAME];
        scanf("%f %d %s",&gpa,&level,name);
        if(Update_BST(*root,id,gpa,name,level)==0) printf("SUCCESS on BST\n");
        Update_LL(temp,name,gpa,level);
        printf("SUCCESS on LL\n");
        break;
    }
    case 6:
        break;
    default:
        printf("!Invalid choice\n");
        break;
    }
}

int main(){

    LLNode* head=NULL;
    BSTNode* root=NULL;
     int choice;
    do{
        Print_Menu();
        scanf("%d",&choice);
        Actions(choice,&root,&head);

    }while(choice!=6);

    Free_BST(&root);
    Free_LL(&head);

    printf("Thank u for testing from vigilanttea\n");
    
    return 0;
}