//https://binarysearch.com/problems/Binary-Search-Tree-Typo

/*
You are given a binary tree root which is almost a binary search tree except two nodes' values have been swapped. Return the original binary search tree.
*/

#include<bits/stdc++.h>
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

void inorder(Tree* root, Tree* &prev, Tree* &node1, Tree* &node2)
{
    if(root == NULL)
        return;
    
    inorder(root->left, prev, node1, node2);
    if(prev != NULL and prev->val > root->val)
    {   
        if(node1 == NULL)
            node1 = prev;
        node2 = root;
    }
    prev = root;
    inorder(root->right, prev, node1, node2);

}
Tree* solve(Tree* root) {
    Tree *node1 = NULL, *node2 = NULL, *prev = NULL;

    inorder(root, prev, node1, node2);
    swap(node1->val , node2->val);
    return root;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}