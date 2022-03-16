//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

class Solution {
public:
    void vertical_order(TreeNode *root, int row, int col, map<int, map<int, multiset<int>>>&mp)
    {
        if(root == NULL)
            return;

        vertical_order(root->left, row+1, col-1, mp);
        mp[col][row].insert(root->val);
        vertical_order(root->right, row+1, col+1, mp);
    }   
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        vertical_order(root, 0, 0, mp);
        
        vector<vector<int>>ans;
        for(auto p : mp)
        {
            vector<int>temp;
            for(auto pr : p.second)
            {
                multiset<int>s = pr.second;
                temp.insert(temp.end(), s.begin(), s.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};