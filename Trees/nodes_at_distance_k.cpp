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
void printAtLevelK(Node *root, int k)
{
    if(root == NULL)
        return;
    
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int printNodesAtDistanceK(Node *root, Node *target, int k)
{
    //base case
    if(root == NULL)
    {
        return -1;
    }

    // If reached the target node
    if(root == target)
    {
        //print all descendents at level K
        printAtLevelK(target, k);
        return 0;
    }

    //other case
    int DistanceLeft = printNodesAtDistanceK(root->left, target, k);
    if(DistanceLeft != -1)
    {
        //2 cases
        // Print the current node
        if(DistanceLeft + 1 == k)
        {
            cout<<root->data<<" ";
        }

        // Print the some nodes in the right-subtree
        else{
            printAtLevelK(root->right, k - DistanceLeft - 2);
        }
        return 1 + DistanceLeft;
    }
    int DistanceRight = printNodesAtDistanceK(root->right, target, k);
    if(DistanceRight != -1)
    {
        if(DistanceRight + 1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printAtLevelK(root->left, k - DistanceRight - 2);
        }
        return 1 + DistanceRight;
    }
    return -1;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Node *root = buildTree();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    cout<<"Tree is : "<<endl;
    inorder(root);
    cout<<endl;
    
    Node *target = root->left->right; // Node 5

    int k = 2;

    printNodesAtDistanceK(root, target, k);
    cout<<endl;
    return 0;
}

// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1