



#include <stdio.h>
#define SIZE 100

typedef struct {
    int data[SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is Full\n");
        return;
    }
    s->data[++s->top] = value;
    printf("Inserted %d\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped %d\n", s->data[s->top--]);
}

int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
