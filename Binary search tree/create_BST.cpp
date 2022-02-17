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

bool search(Node *root, int key)
{
    if(root == NULL)
        return false;
    
    if(root->key == key)
        return true;
    else if(key < root->key)
        search(root->left, key);
    else
        search(root->right, key);
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

    printInorder(root);
    cout<<endl;
    if(search(root, 13))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;
    
    if(search(root, 12))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;

    return 0;
}