//  problem 2
//  arrange strings in lexicographical order
//  using singly linked list
//  AUTHOR :: gautam7-github
//  SOLVED


#include <iostream>
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
class Solve
{
private:
	Node *head;

public:
	Solve()
	{
		head = NULL;
	}
	void insertSorted(string nodeData)
	{
		Node *newNode = new Node;
		newNode->data = nodeData;

		if ((head == NULL) || (head->data >= newNode->data))
		{
			newNode->link = head;
			head = newNode;
		}
		else
		{
			Node *current = head;
			while ((current->link != NULL) && (current->link->data <= newNode->data))
			{
				current = current->link;
			}
			newNode->link = current->link;
			current->link = newNode;
		}
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "EMPTY" << endl;
			return;
		}
		Node *trav = head;
		cout << "HEAD -> ";
		while (trav)
		{
			cout << trav->data << " -> ";
			trav = trav->link;
		}
		if (!trav)
			cout << "NULL" << endl;
	}
};
int main()
{
	Solve sudo;
	sudo.insertSorted("hello");
	sudo.display();
	sudo.insertSorted("gello");
	sudo.display();
	sudo.insertSorted("aello");
	sudo.display();
	sudo.insertSorted("zello");
	sudo.display();
	sudo.insertSorted("a");
	sudo.display();
	sudo.insertSorted("aa");
	sudo.display();
	sudo.insertSorted("aab");
	sudo.display();
	sudo.insertSorted("123");
	sudo.display();
	return 0;
}

/*

*/