#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct Node {
    int data;
    struct Node* next;
};
void insertHere(struct Node* node, int item) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}
void insertAfterGivenData(struct Node* head,int data,int item) {
    if (head == NULL)
        return;
    struct Node* temp = head;
    while (temp != NULL) {
        if(temp->data == data)
            insertHere(temp,item);
        temp = temp->next;
    }
}
void linknodebegin(struct Node** head, int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = *head;
    newnode->data = data;
    *head = newnode;
}
struct Node* create() {
    struct Node* head = NULL;
    return head;
}
void display(struct Node* head) {
    struct Node *current = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list: \n");
    while(current != NULL) {
        //Prints each node by incrementing pointer
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
bool isPrime(int n) {
    if (n == 2)
        return true;
    for (int i = 2; i <= n/2 ; ++i) {
        if(n%i==0)
            return false;
    }
    return true;
}
void deleteAllPrimes(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if(isPrime(temp->data) && prev == NULL) {
            *head = temp->next;
        }
        else if(isPrime(temp->data))
            prev->next = temp->next;
        prev = temp;
        temp = temp->next;
    }
}
int main() {
    struct Node* head = create();
    linknodebegin(&head,2);
    linknodebegin(&head,3);
    linknodebegin(&head,4);
    linknodebegin(&head,7);
    deleteAllPrimes(&head);
    display(head);
}
