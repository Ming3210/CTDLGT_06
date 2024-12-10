#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef struct {
	int arr[MAX];
	int top;
} Stack;



// Khoi tao 1 stack
void initial(Stack* stack){
	stack->top = -1;
}
// Kiem tra stack co rong hay ko
int isEmpty(Stack *stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
	
}

// Kiem tra ngan xep co bi day hay ko
int isFull(Stack* stack){
	if(stack->top >= MAX-1){
		return 1;
	}
	return 0;
}

void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("Ngan xep day\n");
		return;
	}
	stack->arr[++(stack->top)] = value;
}

void printStack(Stack* stack){
	for(int i = stack->top;i >= 0;i--){
		printf("%d\n",stack->arr[i]);
	}
}

void pop(Stack* stack){
		if(isFull(stack) == 1){
		printf("Ngan xep day\n");
		return;
	}
	stack->arr[(stack->top)] = stack->arr[--(stack->top)];
}

void peek(Stack* stack){
	if(isEmpty(stack) == 1){
			printf("Danh sach rong\n");
	}
	printf("%d\n",stack->arr[stack->top]);
}

int main(){
	int choice;
	int value;
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
    printf("Gia tri cuoi: ");
	peek(&stack);
	
	return 0;
}
