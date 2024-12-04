#include <stdio.h>
#include "stdlib.h"
#define MAX 1000
int priority(char item) {
    if(item == '(')
        return 1;
    else if(item =='+' || item == '-')
        return 2;
    else if (item == '*' || item == '/')
        return 3;
    else
        return 0;
}
char getTopStr(char* stack,int top) {
    if(top == -1)
        return '0';
    return stack[top];
}
void pushStr(char* stack,int *top,char item) {
    if(*top == MAX-1)
        printf("Stack is full\n");
    else {
        *top = *top + 1;
        stack[*top] = item;
    }
}
char popStr(char* stack,int *top) {
    char item;
    if(*top == -1)
        return '0';
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
void convertToPostfix(char* p, char* ans) {
    char* stack = (char*) malloc(MAX*sizeof(char));
    int top = -1,k=0;
    char item;
    for(int i = 0;p[i+1] != '\0';i++) {
        switch (p[i]) {
            case '(':
                pushStr(stack,&top,p[i]);
                break;
            case ')':
                while (1) {
                    item = popStr(stack,&top);
                    if(item == '(')
                        break;
                    else
                        ans[k++] = item;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if(priority(getTopStr(stack,top)) < priority(p[i])) {
                    pushStr(stack,&top,p[i]);
                }
                else if(priority(getTopStr(stack,top)) == priority(p[i])) {
                    ans[k++] = popStr(stack,&top);
                    pushStr(stack,&top,p[i]);
                }
                else {
                    while (priority(getTopStr(stack,top)) > priority(p[i])) {
                        if(getTopStr(stack,top) == '(')
                            break;
                        else
                            ans[k++] = popStr(stack,&top);
                    }
                    pushStr(stack,&top,p[i]);
                }
                break;
            case ' ':
                continue;
            default:
                ans[k++] = p[i];
        }
    }
    while (top != -1) {
        item = popStr(stack,&top);
        ans[k++] = item;
    }
    ans[k] = '\0';
}
int main() {
    char p[256],ans[256];
    printf("Enter the infix expression");
    fgets(p,255,stdin);
    convertToPostfix(p, ans);
    printf("Result:%s\n",ans);
}