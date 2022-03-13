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

int height(Node *root)
{
    if(root==NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l,r);
}
pair<int, bool> isHeightBalanced(Node *root)
{
    pair<int, bool>p, left, right;

    if(root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }

    left = isHeightBalanced(root->left);
    right = isHeightBalanced(root->right);

    int height = 1 + max(left.first, right.first);

    if(abs(left.first - right.first) <= 1 and left.second and right.second)
    {
        return make_pair(height, true);
    }

    return make_pair(height, false);
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node *root = buildTree();
    inorder(root);

    pair<int, bool>p = isHeightBalanced(root);
    if(p.second == true)
        cout<<"tree is height balanced"<<endl;
    else   
        cout<<"Tree is not a height balanced tree"<<endl;

    cout<<endl;
    return 0;
}
// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1