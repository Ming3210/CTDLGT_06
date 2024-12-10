#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Khoi tao stack
void initial(Stack* stack) {
    stack->top = -1;
}

// Kiem tra stack co rong hay khong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Kiem tra stack co day hay khong
int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

// Them phan tu vao stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep day\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

// In stack tu tren xuong duoi
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Cac phan tu trong ngan xep:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main() {
    Stack stack;
    initial(&stack);

    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

  
    for (int i = 0; i < n; i++) {
        int value;
        printf("Gia tri %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    printStack(&stack);

    return 0;
}