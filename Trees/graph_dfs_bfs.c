#include <stdio.h>
#include <stdlib.h>
#define max 10

struct node{
    int info;
    struct node *link;
};

void addEdge(struct node **adjList,int src,int dest){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = dest;
    newNode->link = NULL;
    newNode->link = adjList[src];
    adjList[src] = newNode;

    //if graph is undirected
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = src;
    newNode->link = NULL;
    newNode->link = adjList[dest];
    adjList[dest] = newNode;
}

//print graph
void printGraph(struct node **adjList,int v){
    for(int i=0;i<v;i++){
        struct node *save = adjList[i];
        printf("vertex %d :",i);
        while(save != NULL){
            printf("%d ",save->info);
            save = save->link;
        }
        printf("\n");
    }
}

//BFS
void bfs(struct node **adjList,int startVertex){
    int visited[max] = {0};
    int queue[max];
    int front = 0,rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from verted %d :",startVertex);
    while(front < rear){
        int currentVertex = queue[front++];
        printf("%d ",currentVertex);

        struct node *save = adjList[currentVertex];
        while(save != NULL){
            int adjVertex = save->info;
            if(!visited[adjVertex]){
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            save = save->link;
        }
    }
    printf("\n");
}

//DFS
void dfsUntil(struct node **adjList,int vertex,int visited[]){
    visited[vertex] = 1;
    printf("%d ",vertex);

    struct node *save = adjList[vertex];
    while(save != NULL){
        if(!visited[save->info]){
            dfsUntil(adjList,save->info,visited);
        }
        save = save->link;
    }
}

void dfs(struct node **adjList,int startVertex){
    int visited[max] = {0};
    printf("DFS traversal %d :",startVertex);
    dfsUntil(adjList,startVertex,visited);
    printf("\n");
}

void main () {
    struct node** adjList = (struct node**)malloc(max * sizeof(struct node*));
    addEdge(adjList,2,1);
    addEdge(adjList,2,0);

    printGraph(adjList,2);
    bfs(adjList,2);
    dfs(adjList,2);
}