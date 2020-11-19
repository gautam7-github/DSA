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
        link = NULL;
    }
};
class CLL
{
private:
    Node *last;

public:
    CLL()
    {
        last = NULL;
    }
    void insertStart(int nodeData)
    {
        // create a new Node
        Node *newNode = new Node;
        // put data of newly made Node to nodeData
        newNode->data = nodeData;

        // check if last pointer is NULL
        if (last == NULL)
        {
            last = newNode;
            newNode->link = last;
        }
        else
        {
            newNode->link = last->link;
            last->link = newNode;
            last = newNode;
        }
    }
    void displayList()
    {
        if (last == NULL)
        {
            cout << "CANNOT DISPLAY : ";
            cout << "LINKED LIST - UNDERFLOW\n";
        }
        else
        {
            Node *trav;
            trav = last->link;
            cout << "\nHEAD - - > ";
            while (trav != last)
            {
                cout << trav->data << "- - >";
                trav = trav->link;
            }
            cout << trav->data << "- - >";
            cout << "NULL\n";
        }
    }
    void deleteNode(int nodeVal)
    {
        Node *temp, *trav;
        trav = last->link;

        if ((last->link == last) && (last->data = nodeVal))
        {
            temp = last;
            last = NULL;
            delete temp;
            return;
        }
        if (trav->data == nodeVal)
        {
            temp = trav;
            last->link = trav->link;
            delete temp;
            return;
        }
    }
    void searchList(int searchData)
    {
        if (last == NULL)
        {
            cout << "LINKED LIST - UNDERFLOW " << endl;
        }
        else
        {
            Node *searcher = last;
            do
            {
                if (searcher->data == searchData)
                {
                    cout << "FOUND :: " << searchData << endl;
                }
                searcher = searcher->link;
            } while (searcher != last);
        }
    }
};
int main()
{
    cout << "LINKED LIST - CIRCULAR" << endl;

    CLL *list = new CLL;
    list->insertStart(67);
    list->insertStart(78);
    list->searchList(78);
    list->insertStart(89);
    list->insertStart(94);
    list->searchList(94);
    list->displayList();
    list->deleteNode(67);
    list->deleteNode(78);
    list->displayList();

    delete list;
    return 0;
}