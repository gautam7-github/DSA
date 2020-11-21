// Singly Linked List
// Author : GAUTAM
// GITHUB : gautam7-github
// JUST DO IT.

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
    Node *link;

    Node()
    {
        link = NULL;
    }
};
class Slinkedlist
{
private:
    Node *head;

public:
    Slinkedlist()
    {
        head = NULL;
    }
    void insertStart(string nodeData)
    {
        // new node created by using DMA
        Node *newNode = new Node;
        // data in newNode is assigned user data -> nodeData
        newNode->data = nodeData;
        // link of newNode now points to the node originally pointed to by head
        newNode->link = head;
        // head now points to the newly created node
        head = newNode;
    }
    void insertEnd(string nodeData)
    {
        if (head == NULL)
            insertStart(nodeData);
        else
        {
            Node *newNode = new Node;
            Node *temp = head;

            newNode->data = nodeData;
            newNode->link = NULL;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }
    void displayList()
    {

        if (head == NULL)
        {
            cout << "LINKED LIST - EMPTY" << endl;
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
                cout << dispo->data << " -> ";
                dispo = dispo->link;
            }
            if (dispo == NULL)
            {
                cout << "NULL" << endl;
            }
            // freeing up instance of temporary node
            delete dispo;
        }
    }
    void countNodes()
    {
        unsigned int count = 0;

        // checking underflow condition
        if (head == NULL)
        {
            cout << "EMPTY LIST -> " << count << endl;
        }
        else
        {
            assert(head != NULL);
            // counter node created to traverse through the linked list
            Node *counter = new Node;
            // head value has been transferred to temp node
            counter = head;
            // traversing through the list
            while (counter != NULL)
            {
                count++;
                counter = counter->link;
            }

            cout << "TOTAL NODES -> " << count << endl;
            // freeing up instance of temporary node
            delete counter;
        }
    }
    void deleteStart()
    {
        if (head == NULL)
        {
            cout << "LINKED LIST - ERROR - UNDERFLOW" << endl;
        }
        else
        {
            assert(head != NULL);
            // create a new temporary node
            Node *deleter = new Node;
            // get access to first node
            deleter = head;
            // head now points to the object pointed by first node (second node or NULL)
            head = head->link;
            // free up the temporary node and there goes first node with it
            delete deleter;
        }
    }
    bool searchList(string searchVal)
    {
        if (head == NULL)
        {
            cout << "LINKED LIST - ERROR - UNDERFLOW" << endl;
        }
        else
        {
            assert(head != NULL);
            // create a searcher node to traverse through the linked list
            Node *searcher = new Node;
            // give access to searcher
            searcher = head;

            while (searcher != NULL)
            {
                // if node data is the one we want then
                if (searcher->data == searchVal)
                {
                    return true;
                }
                // goto next node
                searcher = searcher->link;
            }
            return false;
        }
    }
    ~Slinkedlist()
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
    cout << "LINKED LISTS" << endl;

    //creating an instance of class SLinkedList using DMA
    class Slinkedlist *list = new Slinkedlist;

    if (!list)
    {
        cout << "HEAP OVERFLOW";
    }
    else
    {
        while (true)
        {
            cout << "1. DISPLAY LIST" << endl;
            cout << "2. INSERT DATA" << endl;
            cout << "3. DELETE NODE" << endl;
            cout << "4. SEARCH LIST" << endl;
            cout << "5. COUNT NODES" << endl;
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
                list->insertEnd(Data);
                break;
            case 3:
                list->deleteStart();
                break;
            case 4:
                cout << "ENTER ELEMENT TO SEARCH : ";
                cin >> searchEle;
                if (list->searchList(searchEle))
                {
                    cout << "FOUND " << searchEle << endl;
                }
                else
                {
                    cout << "NOT FOUND " << searchEle << endl;
                }
                break;
            case 5:
                list->countNodes();
                break;
            case 6:
                delete list;
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << "NOT A VALID CHOICE ... NOOB" << endl;
                break;
            }
        }
    }
    //deleting the instance to free up memory
    delete list;

    return 0;
}