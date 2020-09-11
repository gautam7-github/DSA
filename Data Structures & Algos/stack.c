#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;
int pop()
{
    if (top == -1)
    {
        printf("-- CANNOT POP --\n");
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        return stack[top--];
    }
}
void push(int pushVal)
{
    if (top == MAX - 1)
    {
        printf("-- CANNOT PUSH -- \n");
        printf("STACK OVERFLOW\n");
    }
    else
    {
        top++;
        stack[top] = pushVal;
        printf("%d PUSHED TO STACK\n", pushVal);
        printf("TOP IS NOW : %d\n", stack[top]);
    }
}
int display()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {

        for (int i = top; i >= 0; i--)
        {
            printf("| %d : %d |\n", i, stack[i]);
        }
    }
}
int tell()
{
    if (top == -1)
    {
        printf("-- PUSH ALLOWED --\n");
        printf("STACK UNDERFLOW\n");
        printf("-- POP NOT ALLOWED --\n");
    }
    else
    {
        if (top == MAX - 1)
        {
            printf("\n");
            printf("-- POP ALLOWED --\n");
            printf("THERE ARE %d ELEMENTS IN THE STACK\n", top + 1);
            printf("-- PUSH NOT ALLOWED --\n");
        }
        else
        {
            printf("THERE ARE %d ELEMENTS IN THE STACK\n", top + 1);
        }
    }
}
int main()
{
    tell();
    push(23);
    push(43);
    display();
    tell();
    printf("POPPED : %d\n", pop());
    printf("POPPED : %d\n", pop());
    tell();
    push(45);
    push(56);
    push(66);
    push(67);
    printf("POPPED : %d\n", pop());
    display();
    tell();
}