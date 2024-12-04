//
// Created by ananmay on 10/6/24.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void createList(struct Node* *head, int data) {
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    *head = newnode;
}
int countElements(struct Node* head) {
    int ans = 0;
    while (head != NULL) {
        ans++;
        head = head->next;
    }
    return ans;
}
int detectPresence(struct Node* head, int target) {
    while (head != NULL) {
        if(head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}
int findPosition(struct Node* head, int target, int *position) {
    int pos = 0;
    while (head != NULL) {
        if(head->data == target) {
            *position = pos;
            return 1;
        }
        pos++;
        head = head->next;
    }
    return 0;
}
int findOccurences(struct Node* head, int target,int *occur) {
    int occ = 1;
    while (head != NULL) {
        if(head->data == target) {
           occ++;
        }
        head = head->next;
    }
    if(occ != 1) {
        *occur = occ;
        return 1;
    }
    return 0;
}
void reverseList(struct Node* *head) {
    struct Node* runner = *head,*handler = *head,*catcher = NULL;
    while(runner != NULL) {
        handler = runner;
        runner = runner->next;
        handler->next = catcher;
        catcher = handler;
    }
    *head = handler;
}
void sortList(struct Node* *head) {
    if(*head == NULL)
        return;
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;
    while (current!=NULL) {
        index = current->next;
        while (index != NULL) {
            if(current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
void insertFirst(struct Node* *head, int data) {
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}
void insertAtLast(struct Node* *head,int data) {
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    if(*head == NULL) {
        insertFirst(head,data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;

    }
    temp->next = newnode;
    newnode->next = NULL;
}
int insertAfterPosition(struct Node* *head,int data,int position) {
    if(position < 0 || position >= countElements(*head))
        return 0;
    struct Node* temp = *head;
    struct Node* prev = NULL;

}
int main() {

}