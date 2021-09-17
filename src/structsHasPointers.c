#include <stdio.h>
#include <stdlib.h>

/**
 * dynamic impl. of stack with arrays.
 * below, we need 2 calloc(), 1 for stack, 1 for stack.array.
 */


typedef
struct stack {
    //headers
    int capacity;
    int index;

    //data
    int *array; //holds data

} STACK;

STACK *stack;


void push (int data) {

    if (stack->capacity == 0) {
        perror("stack not initialized");
        return;
    }
    if (stack->index == stack->capacity) {
        perror("stack-full");
        return;
    }

    stack->array[stack->index] = data;
    stack->index++;

}

int pop() {

    int r = stack->array[stack->index - 1];

    stack->array[stack->index - 1] = 0;
    stack->index--;

    return r;
}

//gcc src/structsHasPointers.c -o out/structsHasPointers  && out/structsHasPointers
int main(int argc, char **argv) {

    //below we need 2 calloc
    stack = (STACK *) calloc(1, sizeof(STACK));
    stack->capacity = 10;
    stack->index = 0;

    stack->array = (int *) calloc(stack->capacity, sizeof(int));

    //push
    push(100);
    push(150);
    push(170);
    push(190);
    push(200);
    push(210);


    //pop
    int k = pop();
    printf("%d \n", k);

    //display the rest
    for (int i = 0; i < stack->index; i++)
        printf("%d ", stack->array[i]);


    return 0;
}