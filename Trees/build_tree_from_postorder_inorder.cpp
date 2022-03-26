//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal


class Solution {
public:
    unordered_map<int, int>mp;
    TreeNode* build(vector<int>& postorder, int &k, vector<int>& inorder, int i, int j)
    {
        if(i > j)
            return NULL;
        
        int key = postorder[k];
        int pivot = mp[key];
        TreeNode *root = new TreeNode(inorder[pivot]);
        k--;
        
        // Here we need to go right first because in postorder (left, right, root)
        // Since we inserting node using variable 'k' from last value of postorder, the postorder sequence will be traversed in reverse order thats why build tree in root => right => left manner.
        root->right = build(postorder, k, inorder, pivot+1, j);
        root->left = build(postorder, k, inorder, i, pivot-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        
        int k = postorder.size()-1;
        return build(postorder, k, inorder, 0, inorder.size()-1);
    }
};