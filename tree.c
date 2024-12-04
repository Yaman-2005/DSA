//
// Created by ananmay on 25/11/24.
//
#include "stdlib.h"
#include "stdio.h"
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isFound;
};
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insertNode(struct Node* root,int data) {
    if (root==NULL)
        return createNode(data);
    if (root->data < data) {
        root->right = insertNode(root->right,data);
    }
    if (root->data > data) {
        root->left = insertNode(root->left,data);
    }
    return root;
}
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct Node* searchNode(struct Node* root,int target) {
    struct Node *temp = (struct Node*) malloc(sizeof (struct Node));
    if(root == NULL) {
        temp->isFound = 0;
        return temp;
    }
    if(root->data == target) {
        temp->isFound = 1;
        return temp;
    }
    if(root->data < target)
        return searchNode(root->right,target);
    if(root->data > target)
        return searchNode(root->left,target);
    return temp;

}
struct Node* minValueNode(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    int c,data;
    struct Node* root = NULL;
    do {
        printf("\nPress 1 to insert\nPress 2 to traverse inorder\nPress 3 to traverse preorder\nPress 4 to traverse postorder\nPress 5 to delete\nPress 6 to search\nPress 7 to quit");
        scanf("%d",&c);
        switch (c) {
            case 1:
                printf("Enter the data");
                scanf("%d",&data);
                root = insertNode(root,data);
                printf("\n");
                break;
            case 2:
                printf("Printing Nodes:");
                inorder(root);
                break;
            case 3:
                printf("Printing Nodes:");
                preorder(root);
                break;
            case 4:
                printf("Printing Nodes:");
                postorder(root);
                break;
            case 5:
                printf("Enter the data to delete:");
                scanf("%d",&data);
                root = deleteNode(root,data);
                break;
            case 6:
                printf("Enter the target");
                scanf("%d",&data);
                struct Node* temp = searchNode(root,data);
                if(temp->isFound)
                    printf("Target Found");
                else
                    printf("Target not found");
                break;
            case 7:
                break;
            default:
                printf("Wrong choice");
        }
    } while (c != 7);
}