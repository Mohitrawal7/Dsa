// Breadth first search program for graph on C

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front;
    int rear;
    int items[MAX];
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q))
        printf("Queue is full\n");
    else {
        if (isEmpty(q)) q->front = 0;
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front >= q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return item;
    }
}

void bfs(int graph[MAX][MAX], int n, int start) {
    Queue q;
    initializeQueue(&q);
    int visited[MAX] = {0};

    printf("BFS starting from vertex %d: ", start);
    enqueue(&q, start);
    visited[start] = 1;

    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}
