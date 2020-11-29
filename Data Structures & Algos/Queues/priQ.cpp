// TOPIC : PRIORITY QUEUES
// Used : STL Library
// remember to use g++ -std=c++14 to make emplace function work
#include <iostream>
#include <queue>
using namespace std;
class pQ
{
private:
    priority_queue<int> pq;

public:
    pQ()
    {
        cout << "PQ HAS BEEN CREATED..." << endl;
    }
    void push(int item)
    {
        cout << "INSERTED : " << item << endl;
        pq.emplace(item);
    }
    void show()
    {
        priority_queue<int> temp = pQ::pq;
        if (temp.empty())
        {
            cout << "PRIORITY Q IS EMPTY..." << endl;
        }
        else
        {
            while (!temp.empty())
            {
                cout << temp.top() << "\t";
                temp.pop();
            }
            cout << endl;
        }
    }
};
int main()
{
    cout << "Priority Queues" << endl;
    class pQ pq;
    pq.show();
    pq.push(23);
    pq.push(78);
    pq.show();
    return 0;
}