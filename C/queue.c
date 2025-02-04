// //Array implementation of queue



// #include <stdio.h>
// #define SIZE 100

// int queue[SIZE];
// int front = -1, rear = -1;

// void enqueue(int value) {
//     if (rear == SIZE - 1)
//         printf("Queue is Full\n");
//     else {
//         if (front == -1) front = 0;
//         queue[++rear] = value;
//         printf("Inserted %d\n", value);
//     }
// }

// void dequeue() {
//     if (front == -1 || front > rear) 
//         printf("Queue is Empty\n");
//     else {
//         printf("Removed %d\n", queue[front++]);
//         if (front > rear) front = rear = -1;
//     }
// }

// int main() {
//     enqueue(1);
//     enqueue(2);
//     enqueue(3);
//     dequeue();
//     dequeue();
//     dequeue();
//     return 0;
// }






#include <stdio.h>
#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Removed %d\n", q->data[q->front++]);
    if (q->front > q->rear) initQueue(q);
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}