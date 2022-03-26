//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree

// Last node of the every column will be the bottom view of tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int>mp;
        vector<int>ans;
        
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            pair<Node*, int>p = q.front();
            int col = p.second;
            Node* t = p.first;
            mp[col] = t->data;
            
            q.pop();
            if(t->left)
                q.push({t->left, col-1});
            if(t->right)
                q.push({t->right, col+1});
        }
        for(auto p : mp)
            ans.push_back(p.second);
        return ans;
    }
};