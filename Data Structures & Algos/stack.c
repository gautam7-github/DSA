#include <stdio.h>
#define MAX 15
int stack[MAX], top = -1;
int pop()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        return stack[top--];
    }
}
int push()
{
}
int display()
{
}
int tell()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        if (top == MAX - 1)
        {
            printf("STACK IS FULL\n");
            printf("STACK OVERFLOW\n");
        }
        else
        {
            printf("THERE ARE %d ELEMENTS IN THE STACK\n", top + 1);
        }
    }
}
int main()
{
}