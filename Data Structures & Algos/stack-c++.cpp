#include <iostream>
using namespace std;
//stacks
class stack
{
private:
    // top value of stack
    int top;
    // a pointer to allocate specified block of memory
    int *array;
    // a secondary variable used to store MAX capacity of Stack
    int MAX_STACK;

public:
    //constructer to initialise stack limits and variables
    //TODO Optimise code by using DMA
    stack(int max)
    {
        // top is initialised to -1
        top = -1;
        // max value taken in as parameter and then transferred to MAX_STACK
        MAX_STACK = max;
        // size is max and memory has been allocated
        array = new (nothrow) int[max];
        if (!array)
        {
            cout << "TASK FAILED SUCCESSFULY" << endl;
        }
        else
        {
            cout << "  MAX CAPACITY : " << MAX_STACK << endl;
            cout << "      TOP      : " << top << endl;
            cout << "----------------------" << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == MAX_STACK - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int pushItem)
    {
        if (isFull())
        {
            cout << "CANNOT PUSH " << pushItem << " - STACK FULL" << endl;
        }
        else
        {
            top++;
            array[top] = pushItem;
            cout << "PUSHED : " << pushItem << endl;
            cout << "TOP    : " << top << endl;
            cout << "LEFT   : " << MAX_STACK - (top + 1) << endl;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "CANNOT POP TOP - STACK EMPTY" << endl;
        }
        else
        {
            int popVal = array[top];
            top--;
            return popVal;
        }
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << " | " << i << " : " << array[i] << " | " << endl;
        }
        cout << " ---------" << endl;
    }
    void peek()
    {
        cout << "WELCOME TO PEEK" << endl;
        if (top == -1)
        {
            cout << "STACK HAS UNDERFLOWED" << endl;
        }
        else
        {
            cout << "PEEK SAYS TOP IS : " << array[top] << endl;
        }
    }
};

int main()
{
    int choice, pushVal, size_stack;
    cout << "ENTER SIZE OF STACK : " << endl;
    cin >> size_stack;
    cout << "NOTE THAT IT CANNOT BE CHANGED... " << endl;
    //calling stack class constructer
    class stack s(size_stack);

    do
    {
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY" << endl;
        cout << "5. EXIT" << endl;
        cout << "ENTER CHOICE : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "VALUE TO PUSH - " << endl;
            cin >> pushVal;
            s.push(pushVal);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "GOODBYE" << endl;
            return 0;
            break;
        default:
            cout << "RETRY" << endl;
            break;
        }
    } while (true);

    return 0;
}
