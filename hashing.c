#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct Node *next;
}Node;
Node *map[10];
void init() {
    for(int i=0;i<10;i++)
        map[i]=NULL;
}
Node *createNode(int x){
    Node *head=(Node *)malloc(sizeof(Node));
    head->data=x;
    head->next=NULL;
    return head;
}
int find(int x) {
    return x%10;
}
void insert(int x) {
    int index=find(x);
    if(!map[index])
        map[index]= createNode(x);
    else {
        Node *temp= createNode(x);
        temp->next=map[index];
        map[index]=temp;
    }
    printf("%d inserted at index %d in hashtable\n",x,index);
}
void search(int x) {
    int index=find(x);
    Node *temp=map[index];
    while(temp) {
        if(temp->data == x) {
            printf("%d is present at %d in the hashtable\n",x,index);
            return;
        }
        temp=temp->next;
    }
    printf("%d is not present in the hashtable\n",x);
}
void del(int x) {
    int index=find(x);
    Node *temp=map[index],*prev=NULL;
    while(temp && temp->data != x) {
        prev=temp;
        temp=temp->next;
    }
    if(!temp)
        printf("%d is not present in the hashtable\n",x);
    else if(!prev) {
        map[index]=map[index]->next;
        free(temp);
    }
    else {
        prev->next=temp->next;
        free(temp);
    }
}
void displayTable() {
    for(int i=0;i<10;i++) {
        printf("[%d]: ",i);
        Node *temp=map[i];
        while(temp) {
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int c,data;
    init();
    do {
        printf("\nPress 1 to insert\nPress 2 to search\nPress 3 to delete\nPress 4 to display\nPress 5 to exit:");
        scanf("%d",&c);
        switch(c) {
            case 1: printf("Enter element:");
                scanf("%d",&data);
                insert(data);
                break;
            case 2: printf("Enter element:");
                scanf("%d",&data);
                search(data);
                break;
            case 3: printf("Enter element:");
                scanf("%d",&data);
                del(data);
                break;
            case 4:
                displayTable();
                break;
            case 5: return 0;
            default : printf("Invalid user input\n");
        }
    }while(c != 5);
}