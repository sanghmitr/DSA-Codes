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
    if(root == NULL)
        return 0;
    
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r)+1;
}
int diameter(Node* root) {
    if(root == NULL)
        return 0;
    
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    
    return max({d1, d2, d3});
}

class HDPair{
    public:
        int height;
        int diameter;
};   

HDPair optDiameter(Node *root)
    {
        HDPair p;
        if(root == NULL)
        {
            p.height = 0;
            p.diameter = 0;
            return p;
        }

        HDPair left = optDiameter(root->left);
        HDPair right = optDiameter(root->right);

        p.height = max(left.height, right.height) + 1;
        
        int d1 = left.height + right.height;
        int d2 = left.diameter;
        int d3 = right.diameter;

        p.diameter = max({d1,d2,d3});
        return p;
    }


int diameter1(Node *root, int &ans)
{
    if(root == NULL)
        return 0;
    
    int left = diameter1(root->left, ans);
    int right = diameter1(root->right, ans);

    ans = max(ans, left+right);
    return max(left, right)+1;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Node *root = buildTree();
    inorder(root);
    cout<<endl<<"Diameter is : "<<diameter(root)<<endl;
    cout<<"Optimized diameter is : "<<optDiameter(root).diameter<<endl;

    int ans = 0;
    diameter1(root, ans);
    cout<<endl<<"New Diameter is : "<<ans<<endl;
    return 0;
}
// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1