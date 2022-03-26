//https://leetcode.com/problems/count-complete-tree-nodes

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
             return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh)
            return pow(2, lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int leftHeight(TreeNode *root)
    {
        int height = 0;
        while(root != NULL)
        {
            root = root->left;
            height += 1;
        }
        return height;
    }
    
    int rightHeight(TreeNode *root)
    {
        int height = 0;
        while(root != NULL)
        {
            root = root->right;
            height += 1;
        }
        return height;
    }
};