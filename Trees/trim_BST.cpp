//https://leetcode.com/problems/trim-a-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return root;
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        if(root->val < low or root->val > high)
        {
            if(root->left == NULL and root->right == NULL)
                return NULL;
            else if(root->left == NULL and root->right != NULL)
                return root->right;
            else if(root->left != NULL and root->right == NULL)
                return root->left;
        }
        
        return root;
    }
};