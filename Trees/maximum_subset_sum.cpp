//Find the largest sum of subset of nodes in a binary tree,
//such that if a node is include in the sum then its parent and 
//children must not be included in the subset sum

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d)
        {
            data = d;
            left = NULL,right = NULL;
        }
};

Node* buildTree()
{
    int d;
    cin>>d;
    if(d == -1)
        return NULL;
    
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void inorder(Node* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

class Pair
{
    public:
        int inc;
        int exc;
};

Pair maxSubsetSum(Node *root)
{
    Pair p;
    if(root == NULL)
    {
        p.inc = p.exc = 0;
        return p;
    }

    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    //If we include the current node
    p.inc = root->data + left.exc + right.exc;

    //If we do not include the current node
    p.exc = max(left.inc, left.exc) + max(right.inc, right.exc);

    return p;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node *root = buildTree();
    cout<<"Tree is : "<<endl;
    inorder(root);
    cout<<endl;
    
    Pair ans = maxSubsetSum(root);
    cout<<"Max Subset sum is : "<<max(ans.inc , ans.exc);
    return 0;
}

// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1