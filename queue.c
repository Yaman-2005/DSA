//
// Created by ananmay on 6/12/24.
//
#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int data;
    struct Queue* next;
};
struct Queue* front = NULL,*rear = NULL;
void enqueue(int data) {
    struct Queue* new = (struct Queue*)malloc(sizeof(struct Queue));
    new->data = data;
    if(front == NULL && rear == NULL) {
        front = new;
        rear = new;
    }
    new->next = NULL;
    rear = new;
}
void dequeue() {
    struct Queue* new = (struct Queue*)malloc(sizeof(struct Queue));
    if(front == NULL)
        printf("Queue is empty");
    else {
        new = front;
        new = new->next;
        printf("%d is deleted",new->data);
        front = new;
    }
}
void display() {
    struct Queue* temp = front;
    while (temp->next != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main() {
    int ch,dt;
    do {
        printf("Press 1 to push\nPress 2 to pop\nPress 3 to display:");

        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter the data:");
            scanf("%d",&dt);
            enqueue(dt);
            break;
            case 2:
                dequeue();
            break;
            case 3:
                display();
            break;
            case 4:
                break;
        }
    } while (ch!=4);
}