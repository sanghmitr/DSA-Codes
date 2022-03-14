//https://leetcode.com/problems/symmetric-tree

class Solution {
public:
    bool symmetricHelper(TreeNode *left, TreeNode *right)
    {
        if(left == NULL or right == NULL)
            return left == right;
        
        if(left->val != right->val)
            return false;
        
        return symmetricHelper(left->left, right->right) and symmetricHelper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return symmetricHelper(root->left, root->right);
    }
};