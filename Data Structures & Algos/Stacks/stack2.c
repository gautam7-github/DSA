#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned int MAX_STACK;
    int *array;
};
struct Stack *createStack(unsigned int MAX)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->MAX_STACK = MAX;
    stack->top = -1;
    stack->array = (int *)malloc(stack->MAX_STACK * sizeof(int));
    return stack;
}
int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("CANNOT POP - STACK UNDERFLOW");
    }
    else
    {
        int popVal = stack->array[stack->top];
        stack->top--;
        return popVal;
    }
}

void push(struct Stack *stack)
{
}
int main()
{
    struct Stack *stack = createStack(10);
    return 0;
}
