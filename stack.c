#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#define MAX 5
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
    if(isEmpty(top))
        printf("stack is empty\n");
    for(int i = top;i>= 0;i--) {
        printf("%d\n",stack[i]);
    }
}
int main() {
    int top = -1;
    int* stack = (int*)calloc(MAX, sizeof(int));
    int c;
    do {
        int item;
        fflush(stdin);
        printf("Press 1 to push\nPress 2 to pop\n press 3 to get topmost element\nPress 4 to check full\nPress 5 to check empty\nPress 6 to display\nPress 7 to quit");
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Enter data:");
                scanf("%d",&item);
                push(stack,&top,item);
                break;
            case 2:
                item = pop(stack,&top);
                if (!item)
                    break;
                printf("%d was deleted\n",item);
                break;
            case 3:
                item = getTop(stack,top);
                if(!item)
                    printf("Stack is empty\n");
                else
                    printf("%d is topmost element\n",item);
                break;
            case 4:
                if(isFull(top))
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 5:
                if(isEmpty(top))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 6:
                display(stack,top);
                break;
            case 7:
                break;
            default:
                printf("wrong choice\n");
        }
    }while(c!=7);
}



