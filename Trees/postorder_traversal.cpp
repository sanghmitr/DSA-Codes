// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<bits/stdc++.h>
using namespace std;

//Iterative
vector<int> postorderTraversal(TreeNode *root)
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

        if (temp->left)
        {
            st.push(temp->left);
        }
        if (temp->right)
        {
            st.push(temp->right);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}