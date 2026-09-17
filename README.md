# Student Record System - C
> by vigilanttea 

Dual data-structure implementation for student records. Same data lives in both a Linked List and a BST.

Stack: C, malloc/free, pointers, modular headers

Structure:
students.h -> Student struct
linked_list.h -> LLNode
bst.h -> BSTNode
linked_list.c -> Add_LL, Delete_LL, Search_LL, Display_LL, Update_LL, Free_LL
bst.c -> Insert_BST, Delete_BST, Search_BST, Display_BST, Update_BST, Find_Min, Free_BST
main.c -> Create_student, Print_Menu, Actions

How to Run:
gcc main.c linked_list.c bst.c -o students_db -Wall
./students_db

Menu:
1. Add new student
2. Search student
3. Display all students
4. Delete student
5. Update Record
6. Exit

Features:
- Add to both LL & BST
- Search by ID O(log n) BST
- Display inorder BST + LL
- Delete handles 3 BST cases
- Update GPA/level/name
- Free_BST & Free_LL no leaks

Author: vigilanttea - Learning DSA in C for Embedded
MIT
