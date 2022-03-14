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

void vertical_order(Node *root, int d, map<int, vector<int>>&mp)
{
    if(root == NULL)
        return;
    
    vertical_order(root->left, d-1, mp);
    mp[d].push_back(root->data);
    vertical_order(root->right, d+1, mp);
}   
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node *root = buildTree();
    map<int, vector<int>>mp;
    vertical_order(root,0, mp);

    for(auto p : mp)
    {
        for(auto node : p.second)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1