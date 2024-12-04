// parenthesisCheck.c
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAX 1000
bool isEmpty(int top) {
    if(top == -1)
        return true;
    else
        return false;
}
bool isFull(int top) {
    if(top == MAX - 1)
        return true;
    else
        return false;
}
void pushStr(char* stack,int *top,char item) {
    if(isFull(*top))
        printf("Stack is full\n");
    else {
        *top = *top + 1;
        stack[*top] = item;
    }
}
char popStr(char* stack,int *top) {
    char item;
    if(isEmpty(*top))
        return '0';
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
bool isGood(char* p) {
    char* stack = (char*) calloc(MAX, sizeof(char));
    int top = -1,flag = true;
    for(int i = 0;p[i] != '\0';i++) {
        switch (p[i]) {
            case '(':
            case '{':
            case '[':
                pushStr(stack,&top,p[i]);
                break;
            case ')':
                while (true) {
                    char item = popStr(stack,&top);
                    if(item == '(')
                        break;
                    else {
                        flag = false;
                        break;
                    }
                }
                break;
            case '}':
                while (true) {
                    char item = popStr(stack,&top);
                    if(item == '{')
                        break;
                    else {
                        flag = false;
                        break;
                    }
                }
                break;
            case ']':
                while (true) {
                    char item = popStr(stack,&top);
                    if(item == '[')
                        break;
                    else {
                        flag = false;
                        break;
                    }
                }
                break;
        }
    }
    if (isEmpty(top) && flag)
        return true;
    return false;
}
int main() {
    char p[256];
    printf("Enter the input expression");
    fgets(p,256,stdin);
    if(isGood(p))
        printf("String is balanced");
    else
        printf("String is not balanced");
}
