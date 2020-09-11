#include <iostream>
using namespace std;
//stacks
class stack
{
private:
    int top;
    int array[1];

public:
    int MAX_STACK;
    //constructer to initialise stack limits
    stack(int max)
    {
        MAX_STACK = max;
        top = -1;
        cout << " || MAX CAPACITY IS : " << MAX_STACK << endl;
        cout << " || TOP NOW IS      : " << top << endl;
        cout << "----------------------" << endl;
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
    void push(int item)
    {
        if (isFull())
        {
            cout << "CANNOT PUSH " << item << " - STACK FULL" << endl;
        }
        else
        {
            top++;
            array[top] = item;
            cout << "PUSHED : " << item << endl;
            cout << "TOP    : " << top << endl;
            cout << "LEFT   : " << MAX_STACK - (top + 1) << endl;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "CANNOT POP - STACK EMPTY" << endl;
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
};

int main()
{
    class stack s(10);
    s.push(21);
    s.push(22);
    s.display();
    cout << "POPPED - " << s.pop() << endl;
    s.push(35);
    s.push(45);
    s.display();
    cout << "POPPED - " << s.pop() << endl;
    return 0;
}
