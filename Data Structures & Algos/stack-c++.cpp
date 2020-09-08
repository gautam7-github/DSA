#include <iostream>
using namespace std;
//define max limit for stack
#define MAX_STACK 10
//stacks
class stack
{
private:
    int top;
    int array[MAX_STACK];

public:
    //constructer to initialise stack limits
    stack()
    {
        top = -1;
        cout << "MAX CAPACITY IS : " << MAX_STACK << endl;
        cout << "TOP NOW IS : " << top << endl;
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
};

int main()
{
    class stack s;
    if (s.isEmpty())
    {
        cout << "STACK IS EMPTY" << endl;
    }
    else
    {
        cout << "STACK IS NOT EMPTY" << endl;
    }
    if (s.isFull())
    {
        cout << "STACK IS FULL" << endl;
    }
    else
    {
        cout << "STACK IS NOT FULL" << endl;
    }
    s.push(21);
    s.push(22);
    return 0;
}
