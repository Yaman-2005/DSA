#include <stdio.h>
#define MAX 10
void push(int* stack,int *top,int item) {
    if(*top == MAX-1)
        printf("Stack is full\n");
    else {
        *top = *top + 1;
        stack[*top] = item;
    }
}
int pop(int* stack,int *top) {
    int item;
    if(*top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    else {
        item = stack[*(top)];
        *top = *top - 1;
        return item;
    }
}
void DFS(int graph[][MAX], int start, int vertices) {
    int stack[MAX],top=-1,i=vertices-1,visited[MAX]={0},vertex,j;
    printf("DFS Traversal starting from vertex %d:\n", start);
    printf("%d ", start);
    visited[start] = 1;
    while (i != 0) {
        if(graph[start][i] == 1) {
            push(stack,&top,i);
            visited[i] = 1;
        }
        i--;
    }
    while (top != -1) {
        j = 0;
        vertex = pop(stack, &top);
        printf("%d ", vertex);
        while(j != vertices) {
            if(graph[vertex][j] == 1 && visited[j] != 1) {
                push(stack,&top,j);
                visited[j] = 1;
            }
            j++;
        }
    }
}
void addEdge(int graph[][MAX],int u,int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
int main() {
    int vertices,graph[MAX][MAX] = {0},start,c,u,v;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    if(vertices > MAX || vertices <= 0) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    while(1) {
        printf("Enter 1 to Add edge\nEnter 2 to finish and traverse DFS:");
        scanf("%d",&c);
        if(c != 1) break;
        printf("Enter the edges you want to connect:");
        scanf("%d%d",&u,&v);
        if(u >= vertices || v >=vertices) {
            printf("The vertices entered does not exist\n");
            continue;
        }
        addEdge(graph,u,v);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    if(start >= vertices || start < 0) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    DFS(graph, start, vertices);
    return 0;
}