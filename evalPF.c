#include <stdio.h>
#include "stdlib.h"
#define MAX 1000
float getTop(float* stack,int top) {
    return stack[top];
}
void push(float* stack,int *top,float item) {
    if(*top == MAX-1)
        printf("Stack is full\n");
    else {
        *top = *top + 1;
        stack[*top] = item;
    }
}
float pop(float* stack,int *top) {
    float item;
    if(*top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
float evaluatePostfix(char* ans) {
    float* stack = (float*) malloc(MAX*sizeof(int));
    int top = -1;
    float x,y,a;
    int item;
    for(int i = 0;ans[i+1] != '\0';i++) {
        if(ans[i] == '+' || ans[i] == '-' || ans[i] == '*' || ans[i] == '/') {
            x = pop(stack,&top);
            y = pop(stack,&top);
            if(ans[i] == '+')
                a = y + x;
            else if(ans[i] == '-')
                a = y - x;
            else if(ans[i] == '*')
                a = y * x;
            else if(ans[i] == '/')
                a = y / x;
            push(stack,&top,a);
        }
        else {
            item = ans[i] - '0';
            push(stack,&top,item);
        }
    }
    a = getTop(stack,top);
    return a;
}
int main() {
    char p[256];
    float ans;
    printf("Enter the postfix expression");
    fgets(p,255,stdin);
    ans = evaluatePostfix(p);
    printf("Result:%f\n",ans);
}