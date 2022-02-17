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

// Next inorder successor
// We are supposing that target node is given
Node* inorder_successor(Node *root, Node *target)
{
    // If right subtree exists
    if(target->right != NULL)
    {
        Node *t = target->right;
        while(t->left != NULL)
        {
            t = t->left;
        }
        return t;
    }
    //If right subtree do not exists
    Node *temp = root;
    Node *succ = NULL;
    while(temp != NULL)
    {
        if(temp->key > target->key)
        {
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key < target->key)
        {
            temp = temp->right;
        }
        else
            break;
    }
    return succ;
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

    cout<<"Inorder successor of 7 is : "<<inorder_successor(root, root->left->right->right)->key<<endl;
    cout<<"Inorder successor of 10 is : "<<inorder_successor(root, root->right)->key<<endl;
    return 0; 
}