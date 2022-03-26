//https://www.interviewbit.com/problems/path-to-given-node/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool recur(TreeNode *root, int target, vector<int>&ans)
{
    if(root == NULL)
        return false;
    
    ans.push_back(root->val);
    if(root->left == NULL and root->right == NULL and root->val != target)
    {   
        ans.pop_back();
        return false;
    }
    if(root->val == target)
    {
        return true;
    }

    bool l = recur(root->left, target, ans);
    bool r = recur(root->right, target, ans);
    if(l or r)
        return true;

    if(!ans.empty())
        ans.pop_back();
    return false;
}
vector<int>rootToNodePath(TreeNode* A, int B) {
    vector<int>ans;
    recur(A, B, ans);
    return ans;
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}

