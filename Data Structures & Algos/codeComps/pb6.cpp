#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string nameData;
    int key;
    Node(int key, string nameData)
    {
        this->nameData = nameData;
        this->key = key;
    }
};
class HashTable
{
private:
    forward_list<Node> *table;
    int HashSize;
    int getHash(int key)
    {
        return key % HashSize;
    }

public:
    HashTable(int Size)
    {
        this->HashSize = Size;
        table = new forward_list<Node>[HashSize];
    }
    void insertHash(int key, string name)
    {
        Node newNode(key, name);
        int index = getHash(key);
        table[index].push_front(newNode);
    }
    void printHash(int i)
    {
        for (Node &j : table[i])
        {

            cout << "NAME :" << j.nameData << endl;
            cout << "KEY  :" << j.key << endl;
        }
    }
};
int main()
{
    HashTable T(11);
    T.insertHash(22, "JOHN");
    T.insertHash(34, "JAIN");
    T.insertHash(44, "JANE");
    T.insertHash(77, "MINE");
    T.printHash(1);
    return 0;
}