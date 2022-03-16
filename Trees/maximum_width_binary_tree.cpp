//https://leetcode.com/problems/maximum-width-of-binary-tree


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans = 1;
        
        while(!q.empty())
        {
            int n = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            ans = max(ans, end-start+1);
            
            for(int i=0;i<n;i++)
            {
                pair<TreeNode*, int>t = q.front();
                
                int idx = t.second - start;
                q.pop();
                
                if(t.first->left)
                    q.push({t.first->left, (long long)2*idx+1});
                if(t.first->right)
                    q.push({t.first->right, (long long)2*idx+2});
            }
        }
        return ans;
    }
};