//https://leetcode.com/problems/recover-binary-search-tree

class Solution {
    private :
        TreeNode *first, *prev, *middle, *last;
public:
    void recover(TreeNode *root)
    {
        if(root == NULL)
            return;
        
        // if(last == NULL)
        //     last = root;
        
        recover(root->left);
        if(prev != NULL and root->val < prev->val)
        {
            if(first == NULL)
            {
                first = prev;
                middle = root;   
            }
            else
                last = root;
        }
        prev = root;
        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        
        recover(root);
        
        if(last != NULL)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
    }
};