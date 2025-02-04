// Program for simple singlr linked list in C 

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// // Function to create a new node
// Node* createNode(int data) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to insert a node at the beginning
// void insertAtBeginning(Node** head, int data) {
//     Node* newNode = createNode(data);
//     newNode->next = *head;
//     *head = newNode;
// }

// // Function to insert a node at the end
// void insertAtEnd(Node** head, int data) {
//     Node* newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }
//     Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// // Function to delete a node
// void deleteNode(Node** head, int key) {
//     Node* temp = *head;
//     Node* prev = NULL;

//     if (temp != NULL && temp->data == key) {
//         *head = temp->next;
//         free(temp);
//         return;
//     }

//     while (temp != NULL && temp->data != key) {
//         prev = temp;
//         temp = temp->next;
//     }

//     if (temp == NULL) return;

//     prev->next = temp->next;
//     free(temp);
// }

// // Function to print the linked list
// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     Node* head = NULL;

//     insertAtEnd(&head, 1);
//     insertAtEnd(&head, 2);
//     insertAtEnd(&head, 3);
//     insertAtBeginning(&head, 0);
//     printf("Linked List after insertion: ");
//     printList(head);

//     deleteNode(&head, 2);
//     printf("Linked List after deletion: ");
//     printList(head);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}


// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key,position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;  
            case 3:
                printf("Enter data of the node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 4:
                printList(head);
                break;    
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

