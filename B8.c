#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (isEmpty()) {
        printf("Ngan xep rong\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

int peek() {
    if (isEmpty()) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return top->data;
}

void printStack() {
    if (isEmpty()) {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Cac phan tu trong ngan xep:\n");
    Node* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("So luong khong hop le. Vui long nhap so duong.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printStack();

    printf("\nPhan tu tren cung: %d\n", peek());

    printf("\nXoa mot phan tu\n");
    pop();
    printf("Ngan xep sau khi xoa:\n");
    printStack();

    return 0;
}