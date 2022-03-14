//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  
};     

class Solution {
public:
    unordered_map<int, vector<int>>mp;
    vector<int>ans;
    void addEdge(int x, int y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void buildGraph(TreeNode *root)
    {
        if(root == NULL)
            return;
        
        if(root->left)
            addEdge(root->val, root->left->val);
        if(root->right)
            addEdge(root->val, root->right->val);
        
        buildGraph(root->left);
        buildGraph(root->right);
    }
    void dfs(int src, unordered_map<int, bool>&vis, int k)
    {
        vis[src] = true;
        if(k == 0)
        {
            ans.push_back(src);
            return;
        }
        for(auto x : mp[src])
        {
            if(!vis[x])
                dfs(x, vis, k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if( k == 0)
            return {target->val};
        buildGraph(root);
        unordered_map<int, bool>vis;
        for(auto p : mp)
        {
            vis.insert({p.first, false});
            // cout<<"Node is : "<<p.first<<"-->";
            // for(auto x : p.second)
            //     cout<<x<<" ";
            // cout<<endl;
        }
        
        vis[target->val] = true;
        for(auto x : mp[target->val])
        {
            if(!vis[x])
            {
                dfs(x, vis, k-1);
            }
        }
        return ans;
    }
};

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}
