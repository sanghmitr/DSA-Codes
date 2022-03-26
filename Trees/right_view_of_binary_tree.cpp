//https://leetcode.com/problems/binary-tree-right-side-view

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(i == n-1)
                    ans.push_back(t->val);
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        return ans;
    }
};