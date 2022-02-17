
//https://leetcode.com/problems/validate-binary-search-tree

//BST is strict here, means left always contains lesser than root and right always contains greater than root

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    //Recursive solution
    bool check_BST(TreeNode *root, TreeNode *l, TreeNode *r)
    {
        if(root == NULL)
            return true;

        if(l != NULL and l->val >= root->val)
            return false;

        if(r != NULL and r->val <= root->val)
            return false;

        return check_BST(root->left, l, root) and check_BST(root->right, root, r);
    }
    //Using Iterative Inorder traversal 
    bool inorder(TreeNode *root)
    {
        if(root == NULL) return true;
        stack<TreeNode*>s;
        TreeNode *pre = NULL;
        while(root != NULL or !s.empty())
        {
            while(root != NULL)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre != NULL and pre->val >= root->val)
                return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}