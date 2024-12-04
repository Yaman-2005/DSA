#include <stdio.h>
#define MAX 10
int insert(int q[], int *r, int d) {
    if (*r >= MAX) return 0;
    q[(*r)++] = d;
    return 1;
}
int delete(int q[], int *f, int *r, int *d) {
    if (*f == *r) return 0;
    *d = q[(*f)++];
    if(*f==*r)
        *f=*r=0;
    return 1;
}
void BFS(int graph[MAX][MAX], int start, int vertices) {
    int queue[MAX];
    int front = 0, rear = 0;
    int visited[MAX] = {0};
    printf("BFS Traversal starting from vertex %d:\n", start);
    printf("%d ", start);
    visited[start] = 1;
    insert(queue, &rear, start);
    int current;
    while(delete(queue, &front, &rear, &current)) {
        for(int i = 0; i < vertices; i++) {
            if(graph[current][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                insert(queue, &rear, i);
            }
        }
    }
    printf("\n");
}
void addEdge(int graph[][MAX],int u,int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void DFS(int graph[MAX][MAX],int start,int vertices) {

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
        printf("Enter 1 to Add edge\nEnter 2 to finish and traverse BFS:");
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
    BFS(graph, start, vertices);
    return 0;
}