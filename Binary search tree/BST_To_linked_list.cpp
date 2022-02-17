#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

// Pair to capturing the head and tail of the tree
class LinkedList
{   
    public : 
    Node *head;
    Node *tail;
};

LinkedList tree2LL(Node *root)
{
    LinkedList l;

    if(root == NULL)
    {
        return l;
    }

    //4 cases
    if(root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    else if(root->left != NULL and root->right == NULL)
    {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left == NULL and root->right != NULL)
    {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else
    {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head; 
        l.tail = rightLL.tail;
    }
    return l;
}

Node* insert(Node *root, int key)
{
    if(root == NULL)
        return new Node(key);
    
    //recursive case
    if(key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
        root->right = insert(root->right, key);
    return root;
}

void printInorder(Node *root)
{
    if(root == NULL)
        return;

    printInorder(root->left);
    cout<<root->key<<" ";
    printInorder(root->right);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int arr[] = {8,3,10,1,6,14,4,7,13};
    Node *root = NULL;
    for(int x : arr)
    {
        root = insert(root, x);
    }  

    LinkedList l = tree2LL(root);
    Node *temp = l.head;
    while(temp != NULL)
    {
        cout<<temp->key<<" -> ";
        temp = temp->right;
    }
    return 0;  
}