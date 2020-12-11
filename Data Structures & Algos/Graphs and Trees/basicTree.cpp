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
class Tree
{
private:
public:
    void traverse_preorder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->key << " ";
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
    void traverse_inorder(Node *root)
    {
        if (root == nullptr)
            return;
        traverse_preorder(root->left);
        cout << root->key << " ";
        traverse_preorder(root->right);
    }
    void traverse_postorder(Node *root)
    {
        if (root == nullptr)
            return;
        traverse_preorder(root->left);
        traverse_preorder(root->right);
        cout << root->key << " ";
    }
};
int main()
{
    class Tree Trav;
    class Node node;
    Node *root = node.getNode(23);
    // tree  - 23
    Node *child1 = node.getNode(12);
    root->left = child1;
    Node *child2 = node.getNode(34);
    root->right = child2;
    /*
            23
          /   \
        12     34
    */
    Node *child3 = node.getNode(10);
    root->left->left = child3;
    /*
            23
          /   \
        12     34
       /
    10
    */
    Trav.traverse_preorder(root);
    cout << endl;
    Trav.traverse_inorder(root);
    cout << endl;
    Trav.traverse_postorder(root);
    cout << endl;
    return 0;
}