#ifndef TINY_C_PROJECTS_STACK_BASIC_H
#define TINY_C_PROJECTS_STACK_BASIC_H
#include <stdio.h>
#define SIZE 10
typedef struct{
    int top;
    int data[SIZE];
}Stack;
void init(Stack*);
void push(Stack*, int);
int pop(Stack*);
#endif //TINY_C_PROJECTS_STACK_BASIC_H
