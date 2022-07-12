//

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(TreeNode *root, vector<int>&in){
    if(root == NULL)
        return;

    stack<TreeNode *> st;
    TreeNode *t = root;
    while(true){
        if(t != NULL){
            st.push(root);
            t = t->left;
        }
        else{
            while(st.empty() == true)
                break;
            t = st.top();
            st.pop();
            in.push_back(t->val);
            t = t->right;
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}