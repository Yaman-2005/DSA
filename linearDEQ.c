//
// Created by ananmay on 28/8/24.
//
#include "stdio.h"
#include <stdbool.h>
#include "stdlib.h"
#define MAX 5
void insertRear(int* queue,int *front,int *rear,int item) {
    if((*rear+1 == MAX && *front == 0) || (*rear+1 == *front)) {
        printf("Queue overflow");
        return;
    }
    else {
        if(*rear == -1 && *front == -1)
            *front = 0;
        queue[++(*rear)%MAX] = item;
    }
}
int deleteFront(int* queue,int *front,int *rear,int *item) {
    if (*front == -1) {
        printf("Queue is empty");
        return false;
    }
    *item = queue[*front%MAX];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        (*front)++;
    }
    return true;
}
void insertFront(int* queue,int *front,int *rear,int item) {
    if((*front == 0 && *rear == MAX-1) || (*front==rear+1)) {
        printf("Queue Overflow");
        return;
    }
    else {
        if(*rear == -1 && *front == -1) {
            *front = 0;
            *rear = 0;
        }
        if(*front == 0) {
            *front = MAX-1;
        }
        else {
            *front = *front - 1;
        }
        queue[*front] = item;
    }
}
int deleteRear(int* queue,int *front,int *rear,int *item) {
    if (*front == -1) {
        printf("Queue is empty");
        return false;
    }
    *item = queue[*rear];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    }
    if(*rear == 0) {
        *rear = MAX-1;
    }
    else {
        *rear = *rear - 1;
    }
    return true;
}
void print(int* queue,int front,int rear) {
    if(front == -1)
        return;
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != rear);
    printf("\n");
}
int main() {
    int* queue = (int*)calloc(MAX,sizeof(int));
    int c,item,front=-1,rear=-1;
    do {
        printf("Press 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to quit:");
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Enter the item:");
                scanf("%d",&item);
                insertFront(queue,&front,&rear,item);
                printf("\n");
                break;
            case 2:
                if(deleteRear(queue,&front,&rear,&item))
                    printf("%d was deleted",item);
                printf("\n");
                break;
            case 3:
                printf("Queue is:\n");
                print(queue,front,rear);
                printf("\n");
                break;
            case 4:
                break;
            default:
                printf("Wrong choice");
        }
    }while(c!=4);
}