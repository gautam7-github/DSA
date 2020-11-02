// TODO Create a generic linked list

// Linked List Program
// Singly Linked List
// Author : GAUTAM
// GITHUB : gautam7-github

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <new>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *link;

    Node()
    {
        link = NULL;
    }
};
template <class E>
class Slinkedlist
{
private:
    Node<E> *head;

public:
    Slinkedlist()
    {
        head = NULL;
    }
    void insertStart(E nodeData)
    {
        // new node created by using DMA
        Node<E> *newNode = new Node<E>;
        // data in newNode is assigned user data -> nodeData
        newNode->data = nodeData;
        // link of newNode now points to the node originally pointed to by head
        newNode->link = head;
        // head now points to the newly created node
        head = newNode;
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
            Node<E> *dispo = new Node<E>;
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
            Node<E> *deleter = new Node<E>;
            // get access to first node
            deleter = head;
            // head now points to the object pointed by first node (second node or NULL)
            head = head->link;
            // free up the temporary node and there goes first node with it
            delete deleter;
        }
    }
    bool searchList(E searchVal)
    {
        if (head == NULL)
        {
            cout << "LINKED LIST - ERROR - UNDERFLOW" << endl;
        }
        else
        {
            assert(head != NULL);
            // create a searcher node to traverse through the linked list
            Node<E> *searcher = new Node<E>;
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
    class Slinkedlist<string> *list = new Slinkedlist<string>;

    if (!list)
    {
        cout << "HEAP OVERFLOW";
        exit(1);
    }

    while (true)
    {
        cout << "1. DISPLAY LIST" << endl;
        cout << "2. INSERT DATA" << endl;
        cout << "4. SEARCH LIST" << endl;
        cout << "5. DELETE NODE" << endl;
        cout << "3. EXIT WIZARD" << endl;
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
            break;
        case 3:
            delete list;
            exit(EXIT_SUCCESS);
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
            list->deleteStart();
            break;
        default:
            cout << "NOT A VALID CHOICE ... NOOB" << endl;
            break;
        }
    }

    //deleting the instance to free up memory
    delete list;

    return 0;
}