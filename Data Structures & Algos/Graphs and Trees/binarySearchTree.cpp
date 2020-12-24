#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left, *right;
    Node() : left(nullptr), right(nullptr) {}
    Node(int KEYData) : key(KEYData), left(nullptr), right(nullptr) {}
    Node *getNode(int KeyData)
    {
        Node *newNode = new Node(KeyData);
        return newNode;
    }
};
class binarySearchTree
{
private:
public:
    void insertBST(Node *&root, int key)
    {
        if (root == nullptr)
        {
            root = root->getNode(key);
        }

        if (key < root->key)
            insertBST(root->left, key);

        if (key > root->key)
            insertBST(root->right, key);
    }
    void inOrder(Node *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << " " << node->key << " ";
        inOrder(node->right);
    }
};
int main(int argc, char const *argv[])
{
    Node *root = nullptr;
    binarySearchTree BST;
    BST.insertBST(root, 23);
    BST.insertBST(root, 24);
    BST.insertBST(root, 22);
    /*
            23
        22      24
    */
    BST.inOrder(root);
    cout << endl;
    BST.insertBST(root, 25);
    BST.insertBST(root, 12);
    BST.inOrder(root);
    cout << endl;
    return 0;
}
