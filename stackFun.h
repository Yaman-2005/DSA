//
// Created by ananmay on 29/7/24.
//
#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>
#define MAX 1000
#ifndef CLIONPROJECTS_STACKFUN_H
#define CLIONPROJECTS_STACKFUN_H
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
void push(int* stack,int *top,int item) {
    if(isFull(*top))
        printf("Stack is full\n");
    else {
        *top = *top + 1;
        stack[*top] = item;
    }
}
int pop(int* stack,int *top) {
    int item;
    if(isEmpty(*top)) {
        printf("Stack is empty\n");
        return 0;
    }
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
int getTop(int* stack,int top) {
    return stack[top];
}
void display(int* stack,int top) {
    for(int i = top;i>= 0;i--) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void displayStr(char* stack,int top) {
    for(int i = top;i>= 0;i--) {
        printf("%c\n",stack[i]);
    }
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
    if(isEmpty(*top)) {
        printf("Stack is empty\n");
        return '0';
    }
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
char getTopStr(char* stack,int top) {
    if(top == -1)
        return '0';
    return stack[top];
}
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


#endif //CLIONPROJECTS_STACKFUN_H
