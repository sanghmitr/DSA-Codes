// https://leetcode.com/problems/binary-tree-preorder-traversal

#include<bits/stdc++.h>
using namespace std;


//Iterative
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
        return {};

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();
        v.push_back(temp->val);

        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
    // reverse(v.begin(), v.end());
    return v;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}