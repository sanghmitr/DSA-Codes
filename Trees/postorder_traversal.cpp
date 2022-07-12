// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<bits/stdc++.h>
using namespace std;

//Iterative using 2 stacks
vector<int> postOrder(TreeNode *root){
    if(root == NULL)
        return {};
    vector<int> post;

    stack<TreeNode *> s1, s2;
    s1.push(root);
   
    while (!s1.empty()){
        TreeNode *t = s1.top();
        s1.pop();
        s2.push(t);

        if(t->left)
            s1.push(t->left);
        if(t->right)
            s1.push(t->right);
    }
    while(!s2.empty()){
        post.push_back(s2.top()->val);
        s2.pop();
    }
    return post;
}
//Iterative using 1 stack
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