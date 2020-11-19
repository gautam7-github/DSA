#include <iostream>
#include <cassert>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node()
    {
        link = nullptr;
    }
};
class CLL
{
private:
    Node *last;

public:
    CLL()
    {
        last = nullptr;
    }
    void insertEmpty(int nodeData)
    {
        assert(last == NULL);

        Node *newNode = new Node;
        newNode->data = nodeData;
        last = newNode;
        last->link = last;
    }
    void insertStart(int nodeData)
    {
        if (last == NULL)
        {
            insertEmpty(nodeData);
        }
        else
        {
            Node *newNode = new Node;
            newNode->data = nodeData;
            newNode->link = last->link;
            last->link = newNode;
        }
    }
    void displayList()
    {
        Node *trav;
        if (last == NULL)
        {
            
        }
    }
};
int main()
{
    cout << "LINKED LIST - CIRCULAR" << endl;
    return 0;
}