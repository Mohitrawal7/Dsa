



#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;
void createGraph();
void DFS(int vertex);
int main()
{
    createGraph();
    int startVertex;
    printf("\nEnter the starting vertex for DFS traversal : ");
    scanf("%d", &startVertex);
    DFS(startVertex);
    return 0;
}
void createGraph()
    {
        int i, j;
        printf("\nEnter the number of vertices in the graph: ");
        scanf("%d", &numVertices);
        printf("Enter the adjacency matrix:\n");
        for (i = 0; i < numVertices; i++)
        {   
          for (j = 0; j < numVertices; j++)
          {
        scanf("%d", &adj[i][j]);
          }
        }
   }
void DFS(int vertex)
{
int i;
printf("%d ", vertex);
visited[vertex] = 1;
for (i = 0; i < numVertices; i++)
{
if (adj[vertex][i] == 1 && !visited[i])

{ 
DFS(i);
}
}
}