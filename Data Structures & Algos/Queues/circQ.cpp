#include <iostream>
using namespace std;
class cQ
{
private:
    int front;
    int rear;
    int MAX_Q;
    int *array;

public:
    cQ(int max)
    {
        front = rear = -1;
        array = new (nothrow) int[max];
        if (!array)
        {
            cout << "TASK FAILED" << endl;
        }
        else
        {
            MAX_Q = max;
        }
    }
    bool isFull()
    {
        if ((front == 0 && rear == MAX_Q - 1) || (front == rear + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    // Adding an element
    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                if (rear == MAX_Q - 1)
                    rear = 0;
                else
                    rear = rear + 1;
            }
            array[rear] = element;

            cout << "Inserted " << array[rear] << endl;
            cout << "FRONT : " << front << endl;
            cout << "REAR  : " << rear << endl;
        }
    }

    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            element = array[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX_Q;
            }
            cout << "DEQUEUED " << element << endl;
            cout << "FRONT : " << front << endl;
            cout << "REAR  : " << rear << endl;
        }
    }
    void display()
    {
        int i;
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue elements : " << endl;
            cout << "FRONT : " << front << endl;
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                {
                    cout << " " << array[i] << " " << endl;
                }
                cout << "REAR  : " << rear << endl;
            }
            else
            {
                i = front;
                while (i <= MAX_Q - 1)
                {
                    cout << " " << array[i] << " " << endl;
                    i++;
                }
                i = 0;
                while (i <= rear)
                {
                    cout << " " << array[i] << " " << endl;
                    i++;
                }
                cout << "REAR  : " << rear << endl;
            }
        }
    }
    ~cQ()
    {
        cout << "GOODBYE" << endl;
        delete[] array;
    }
};
int main()
{
    cout << "QUEUE - CIRCULAR" << endl;
    class cQ q(10);
    q.display();
    for (int i = 10; i < 21; i++)
    {
        q.enQueue(i);
    }
    q.display();
    q.deQueue();
    q.enQueue(69);
    q.display();
    return 0;
}