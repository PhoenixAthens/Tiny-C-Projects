#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct{
    int size;
    int top;
    int* data;
}stack;
void init(stack*, int);
int push(stack*,int val);
int pop(stack*);
void close(stack*);

void init(stack* sp,int size){
    sp->size=size;
    sp->top=-1;
    sp->data = (int*)malloc(sizeof(int)*size);
}
int push(stack* sp, int val){
    if(sp->top == sp->size-1){
        return 1;
    }
    sp->top++;
    *(sp->data+sp->top) = val;
    return 0;
}
int pop(stack* sp){
    if(sp->top == -1){
        printf("Error: reading values from an empty stack!!");
        return -9045;
    }else{
        int val = *(sp->data + sp->top);
        *(sp->data+sp->top)=0;
        sp->top-=1;
        return val;
    }
}
void close(stack* sp){
    free(sp->data);
}

int main(int argc, char** argv){
    stack s1;
    init(&s1,10);
    int counter = 0;
    int value = 1;
    while(counter < s1.size){
        push(&s1,value);
        value*=12;
        counter++;
    }
   for(int i=0;s1.top!=-1;i++){
        printf("popping: %d\n",pop(&s1));
    }
   close(&s1);
}


