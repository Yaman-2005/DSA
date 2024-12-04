#include "stdio.h"
#include "stdlib.h"
#define MAX 5
void insert(int* queue,int *front,int *rear,int item) {
    if(*rear+1 == MAX) {
        printf("Queue overflow");
        return;
    }
    else {
        if(*rear == -1 && *front == -1)
            *front = 0;
        queue[++*rear] = item;
    }
}
int delete(int* queue,int *front,int *rear,int *item) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty");
        return 0;
    } else {
        *item = queue[(*front)++];
        return 1;
    }
}
void print(int* queue,int front,int rear) {
    for(int i = front;i <= rear;i++) {
        printf("%d ",queue[i]);
    }
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
                insert(queue,&front,&rear,item);
                printf("\n");
                break;
            case 2:
                if(delete(queue,&front,&rear,&item))
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