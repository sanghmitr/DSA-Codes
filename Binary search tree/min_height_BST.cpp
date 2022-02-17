// Given a sorted array, Construct a BST of minimum height

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

void printInorder(Node *root)
{
    if(root == NULL)
        return;

    printInorder(root->left);
    cout<<root->key<<" ";
    printInorder(root->right);
}

Node* min_height_BST(vector<int>&arr, int start, int end)
{
    if(start > end)
        return NULL;

    //Get the middle element and make it root 
    int mid = (start + end)/2;
    Node *root = new Node(arr[mid]);

     //create left & right subtrees recursively 
    root->left = min_height_BST(arr, start, mid -1);
    root->right = min_height_BST(arr, mid+1, end);
    return root;
}

// Find closest node to given target node in BST
int findClosestInBST(Node *root, int target)
{
    int closest;
    int diff = INT_MAX;

    Node *temp = root;
    while(temp != NULL)
    {
        int current_diff = abs(temp->key - target);
        if(current_diff == 0)
            return temp->key;
        
        if(current_diff < diff)
        {
            diff = current_diff;
            closest = temp->key;
        }

        if(temp->key < target)
            temp = temp->right;
        else 
            temp = temp->left;
    }
    return closest;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>arr = {1,2,3,7,9,13,18,19};
    
    int start = 0, end = arr.size()-1;
    Node *root = new Node(arr[(start + end)/2]);

    root = min_height_BST(arr, start, end);
    printInorder(root);

    cout<<endl;
    cout<<findClosestInBST(root, 8)<<endl;
    return 0;
}