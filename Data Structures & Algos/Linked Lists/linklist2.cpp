// Doubly Linked List
// Author : GAUTAM
// GITHUB : gautam7-github

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <new>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node()
    {
        next = prev = NULL;
    }
    Node(string data)
    {
        this->data = data;
    }
};
class DBlinkedlist
{
private:
    Node *head;

public:
    DBlinkedlist()
    {
        head = NULL;
    }
    void insertStart(string nodeData)
    {
        // new Node is created using DMA
        Node *newNode = new Node;
        // nodeData is tranferred to newNode's data
        newNode->data = nodeData;
        // next is now pointing to object prevoiusly pointed to by head
        newNode->next = head;
        // prev is NULL of first Node (always)
        newNode->prev = NULL;
        // check if list is empty
        if (head != NULL)
        {
            // then put prev of head to newNode
            head->prev = newNode;
        }
        // head now points to new Node
        head = newNode;
    }
    void insertEnd(string nodeData)
    {
        if (head == NULL)
        {
            insertStart(nodeData);
        }
        else
        {
            Node *temp = new Node;
            temp->data = nodeData;
            // traversal pointer
            Node *ptr = head;
            // traverse till the end
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            // set position of NEW NODE to END of L.List
            ptr->next = temp;
            // NEXT is NULL of NEW NODE
            temp->next = NULL;
            // PREV points to the second last Node (maybe HEAD)
            temp->prev = ptr;
        }
    }
    void displayList()
    {
        if (head == NULL)
        {
            cout << "LINKED LIST - ERROR - UNDERFLOW" << endl;
            cout << "CANNOT DISPLAY" << endl;
        }
        else
        {
            assert(head != NULL);
            // temp node created to traverse through the linked list
            Node *dispo = new Node;
            // head value has been transferred to temp node
            dispo = head;

            cout << "HEAD -> ";
            while (dispo != NULL)
            {
                cout << dispo->data << " <- - -> ";
                dispo = dispo->next;
            }
            if (dispo == NULL)
            {
                cout << "NULL" << endl;
            }
            // freeing up instance of temporary node
            delete dispo;
        }
    }
    void deleteStart()
    {
        if (head == NULL)
        {
            cout << "LINKED LIST - ERROR - UNDERFLOW" << endl;
            cout << "CANNOT DELETE" << endl;
        }
        else
        {
            // deleter Node created using DMA
            Node *deleter = new Node;
            // give deleter Node access to list
            deleter = head;
            // print the to-be deleted element
            cout << "Element Deleted : " << head->data << endl;
            // move head node to next node in the list
            head = head->next;
            // get out deleter
            delete deleter;
        }
    }
    ~DBlinkedlist()
    {
        delete head;
        cout << "END" << endl;
    }
};
int main()
{
    int choice;
    string Data, searchEle;
    bool ret;
    cout << "LINKED LISTS - DOUBLY" << endl;

    //creating an instance of class SLinkedList using DMA
    class DBlinkedlist *list = new DBlinkedlist;

    if (!list)
    {
        cout << "HEAP OVERFLOW";
    }
    else
    {
        while (true)
        {
            system("cls");
            cout << "1. DISPLAY LIST" << endl;
            cout << "2. INSERT DATA - START" << endl;
            cout << "3. INSERT DATA - END" << endl;
            cout << "4. DELETE DATA" << endl;
            cout << "6. EXIT WIZARD" << endl;
            cout << "ENTER YOUR CHOICE : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                list->displayList();
                break;
            case 2:
                cout << "DATA : ";
                cin >> Data;
                list->insertStart(Data);
                cin.clear();
                break;
            case 3:
                cout << "DATA : ";
                cin >> Data;
                list->insertEnd(Data);
                cin.clear();
                break;
            case 4:
                list->deleteStart();
                break;
            case 6:
                delete list;
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "NOT A VALID CHOICE ... NOOB" << endl;
                break;
            }
            system("pause");
        }
    }
    //deleting the instance to free up memory
    delete list;

    return 0;
}