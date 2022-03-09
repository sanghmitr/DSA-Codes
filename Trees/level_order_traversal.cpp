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

void level_order(Node *root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        //This for loop is added because we want to print next line after each level.
        //This for loop can help to solve many level order traversal problems like left-view, right-view of tree etc. 
        for(int i=0;i<n;i++)
        {
            Node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(i == n-1)
                cout<<endl;

            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    return;
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node *root = buildTree();
    level_order(root);
    return 0;
}

// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1