#ifndef STUDENTS_H
#define STUDENTS_H

#define MAX_NAME 50

typedef struct Student{
    int id;
    char name[MAX_NAME];
    float gpa;
    int level;
}Student;

#endif