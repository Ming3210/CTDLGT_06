#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char arr[MAX];
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
void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep day\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

// Xoa phan tu tren cung cua stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return '\0'; // Tra ve ky tu rong neu stack rong
    }
    return stack->arr[(stack->top)--];
}

int main() {
    Stack stack;
    initial(&stack);

    char input[MAX];
    printf("Nhap mot chuoi (toi da 100 ky tu): ");
    gets(input); 

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        push(&stack, input[i]);
    }

    printf("\nChuoi dao nguoc: ");

    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }

    printf("\n");

    return 0;
}
