//https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int mn = INT_MAX;
    void solve(TreeNode *root, int depth)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL)
        {
            mn = min(mn, 1 + depth);
        }
        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        solve(root, 0);
        return mn;
    }
};