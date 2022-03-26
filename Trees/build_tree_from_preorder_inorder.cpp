//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

class Solution {
public:
    unordered_map<int, int>mp;
    TreeNode* build(vector<int>& preorder, int &k, vector<int>& inorder, int i, int j)
    {
        if(i > j)
            return NULL;
        
        int key = preorder[k];
        int start = mp[key];
        TreeNode *root = new TreeNode(inorder[start]);
        k++;
        
        root->left = build(preorder, k, inorder, i, start-1);
        root->right = build(preorder, k, inorder, start+1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        int k = 0;
        return build(preorder, k, inorder, 0, inorder.size()-1);
    }
};