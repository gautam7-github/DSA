#include <iostream>
using namespace std;
class Q
{
private:
    int front;
    int rear;
    int *array;
    int MAX_Q;

public:
    Q(unsigned int max)
    {
        front = -1;
        rear = -1;
        array = new (nothrow) int[max];
        if (!array)
        {
            cout << "TASK FAILED SUCCESSFULLY" << endl;
        }
        else
        {
            MAX_Q = max;
        }
    }
    void enQ(int enQval)
    {
        if (isFull())
        {
            cout << "CANNOT ENQUEUE " << enQval << " - OVERFLOWED" << endl;
        }
        else
        {
            if (front = -1)
            {
                front++;
            }
            rear++;
            array[rear] = enQval;
            cout << "ENQUEUED : " << enQval << endl;
            cout << "FRONT IS :" << front << endl;
            cout << "REAR IS  :" << rear << endl;
        }
    }
    void deQ()
    {
        if (isEmpty() || front > rear)
        {
            cout << "CANNOT DEQUEUE - UNDERFLOWED" << endl;
        }
        else
        {
            cout << "DEQUEUED ELEMENT : " << array[front] << endl;
            if (front >= rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
            cout << "FRONT IS " << frontval() << endl;
        }
    }
    void display()
    {
        int i;
        if (isEmpty())
        {
            cout << "NOTHING TO DISPLAY" << endl;
        }
        else
        {
            cout << "FRONT IS " << frontval() << endl;
            for (i = front; i <= rear; i++)
            {
                cout << " " << array[i] << " " << endl;
            }
            cout << "REAR IS " << rearval() << endl;
        }
    }
    bool isFull()
    {
        if (rear == MAX_Q - 1)
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
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int frontval()
    {
        return front;
    }
    int rearval()
    {
        return rear;
    }
    ~Q()
    {
        cout << "GOODBYE" << endl;
        delete[] array;
    }
};
int main()
{
    int choice, enQele;
    cout << "QUEUES" << endl;
    class Q queue(10);
    do
    {
        cout << "1. DISPLAY" << endl;
        cout << "2. enQ" << endl;
        cout << "3. deQ" << endl;
        cout << "4. EXIT" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            queue.display();
            break;
        case 2:
            cout << "ENTER ELEMENT TO enQ : " << endl;
            cin >> enQele;
            queue.enQ(enQele);
            break;
        case 3:
            queue.deQ();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "RETRY" << endl;
            break;
        }
    } while (true);

    return 0;
}