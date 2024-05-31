#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int size;
    int top;
    int* data;
}stack;
void init(stack*, int);
void push(stack*, int);
int pop(stack*);
void close(stack*);
void interface();
void printMenu();

void init(stack* sp, int size){
    sp->data = (int*)malloc(sizeof(int)*size);
    sp->top = -1;
    sp->size = size;
}
void close(stack* sp){
    free(sp->data);
}
void push(stack* sp, int value){
    if(sp->top == sp->size-1){
        printf("Overflow, reallocate stack to add more elements!!\n");
        return;
    }else{
        sp->top++;
        sp->data[sp->top]=value;
    }
}
int pop(stack* sp){
    if(sp->top == -1){
        printf("Underflow, pop called on an empty stack!\n");
        return -99999;
    }else{
        int val = sp->data[sp->top];
        sp->data[sp->top]=0;
        sp->top--;
        return val;
    }
}
void interface(){
    printf("Enter the size of stack: ");
    int val;
    scanf("%d",&val);
    stack s1;
    init(&s1,val);
    printMenu();
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&val);
        if(val>=0 && val<=3){
            switch(val){
                case 0:
                    printf("Thanks for your time"
                           "\t\tGoodbye!!\n");
                    close(&s1);
                    exit(0);
                case 1:
                    printf("Enter a value: ");
                    scanf("%d",&val);
                    push(&s1,val);
                    break;
                case 2:
                    printf("popping: %d\n",pop(&s1));
                    break;
                case 3:
                    printMenu();
                    break;
                default:
                    printf("Invalid Argument!\n");
                    break;
            }
        }else{
            printf("Invalid input! Exiting the program!!\n");
            close(&s1);
            exit(1);
        }
    }
}
void printMenu(){
    printf("Option -----------> Function\n"
           "  (0)  -----------> exit the program\n"
           "  (1)  -----------> push a value\n"
           "  (2)  -----------> pop a value\n"
           "  (3)  -----------> print options\n");
}
int main(int argc, char** argv){
    interface();
    return 0;
}