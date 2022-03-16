//https://leetcode.com/problems/path-sum-ii

class Solution {
public:
    vector<vector<int>>ans;
    void hasPathSum(TreeNode* root, int targetSum, vector<int>v) {
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL and (targetSum - root->val) == 0)
        {
            v.push_back(root->val);
            ans.push_back(v);
            return;
        } 
 
        v.push_back(root->val);
        hasPathSum(root->left, targetSum - root->val, v);
        hasPathSum(root->right, targetSum - root->val, v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        hasPathSum(root, targetSum, {});
        return ans;
    }
};