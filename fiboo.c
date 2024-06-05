//fibo
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

//buat stack yang diingin
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

//cek apakah stack penuh
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

//cek apakah stack kosong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//fungsi untuk mendorong
void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
//ini untuk mengambil
int peek(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}
//fungsi untuk menghitung
void fibonacci(int n) {
    if (n <= 0) {
        printf("Masukkan bilangan yang lebih besar dari 0.\n");
        return;
    }

    Stack* stack = createStack(n + 1);

    push(stack, 0);
    if (n > 1) {
        push(stack, 1);
    }

    for (int i = 2; i <= n; i++) {
        int a = pop(stack);
        int b = peek(stack);
        push(stack, a);
        push(stack, a + b);
    }

    printf("\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

    free(stack->array);
    free(stack);
}
// input nilai
int main() {
    int n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}
