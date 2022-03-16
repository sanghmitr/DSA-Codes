//https://leetcode.com/problems/binary-tree-maximum-path-sum


class Solution {
public:
    int maxSum(TreeNode *root, int &ans)
    {   
        if(root == NULL)
            return 0;
        
        int lsum = max(0, maxSum(root->left, ans));
        int rsum = max(0, maxSum(root->right, ans));
        
        ans = max(ans, root->val + lsum + rsum);
        
        return root->val + max(lsum, rsum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }
};