//https://binarysearch.com/problems/Top-View-of-a-Tree


void topView(Tree *root, int row, int col, map<int, pair<int, int>>&mp)
{
    if(root == NULL)
        return;
    
    if (mp.find(col) == mp.end() || row < mp[col].first) {
        mp[col].first = row;
        mp[col].second = root->val;
    }
    topView(root->left, row+1, col-1, mp);
    topView(root->right, row+1, col+1, mp);
}
vector<int> solve(Tree* root) {
    map<int, pair<int, int>>mp;
    topView(root, 0,0, mp);
    vector<int>ans;
    for(auto p : mp)
    {
        pair<int, int>mp1 = p.second;
        int num = mp1.second;
        ans.push_back(num);
    }
    return ans;
}