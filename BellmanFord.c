#include <stdio.h>
#include <limits.h>
void bellman(int edge[][3],int table[][100],int src,int v,int e,int parent[]) {
    for(int i=1;i<=v;i++)
        table[1][i]= (i==src)?0:INT_MAX;
    for(int k=2;k<=v;k++) {
        for(int i=1;i<=v;i++)
            table[k][i]=table[k-1][i];
        for(int i=0;i<e;i++) {
            int u=edge[i][0];
            int v=edge[i][1];
            int wt=edge[i][2];
            if(table[k-1][u]!=INT_MAX&&table[k-1][u]+wt<table[k][v]) {
                table[k][v]=table[k-1][u]+wt;
                parent[v]=u;
            }
        }
    }
}
void path(int parent[],int x) {
    if(parent[x]==-1)
        return;
    path(parent,parent[x]);
    printf("->%d",x);
}
int main() {
    int edge[100][3],e,v,parent[100];
    printf("Enter no of vertices and edges : ");
    scanf("%d%d",&v,&e);
    for(int i=1;i<=v;i++)
        parent[i]=-1;
    printf("Enter source destination and weight of each edge:");
    for(int i=0;i<e;i++)
        scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
    int src;
    printf("Enter source : ");
    scanf("%d",&src);
    int table[100][100];
    bellman(edge,table,src,v,e,parent);
    for(int i=2;i<=v;i++) {
        printf("%d   ",i-1);
        for(int j=1;j<=v;j++) {
            if(table[i][j]==INT_MAX)
                printf("I ");
            else
                printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=v;i++) {
        if(i==src)
            continue;
        printf("1");
        path(parent,i);
        printf(":%d",table[v][i]);
        printf("\n");
    }
}