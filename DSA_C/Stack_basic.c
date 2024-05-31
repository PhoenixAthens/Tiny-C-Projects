#include "Stack_basic.h"

void init(Stack* sp){
    sp->top=-1;
}
void push(Stack* sp, int val){
    if(sp->top == SIZE-1){
        printf("Stack limit exceeded!! <OVERFLOW>\n");
        return;
    }
    sp->top++;
    sp->data[sp->top] = val;
}
int pop(Stack* sp){
    if(sp->top == -1){
        printf("Stack is empty!! <UNDERFLOW>\n");
        return -9090;
    }else{
        int val = sp->data[sp->top];
        sp->top--;
        return val;
    }
}
int main(int argc, char** argv){
    Stack s1;
    init(&s1);
    int counter = 0;
    int val = 3;
    while(counter<SIZE){
        push(&s1,val);
        val*=5;
        counter++;
    }
    while(s1.top!=-1){
        printf("Popping: %d\n",pop(&s1));
    }
    /*
    Popping: 5859375
    Popping: 1171875
    Popping: 234375
    Popping: 46875
    Popping: 9375
    Popping: 1875
    Popping: 375
    Popping: 75
    Popping: 15
    Popping: 3
     */

    printf("Top of Stack: %d\n",s1.top);
    //Top of Stack: -1

    return 0;
}