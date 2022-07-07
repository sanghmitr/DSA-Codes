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
        left = NULL;
        right = NULL;
    }
};

void allInOneTraversal(TreeNode *root){

    vector<int> pre, in, post;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    // 1 -> Preorder
    // 2 -> Inorder
    // 3 -> Postorder

    while(!st.empty()){
        pair<TreeNode*, int>p = st.top();
        st.pop();

        if(p.second == 1){
            pre.push_back(p.first->val);
            st.push({p.first, 2});
            if(p.first->left){
                st.push({p.first->left, 1});
            }
        }
        else if(p.second == 2){
            in.push_back(p.first->val);
            st.push({p.first, 3});
            if(p.first->right){
                st.push({p.first->right, 1});
            }
        }
        else{
            post.push_back(p.first->val);
        }
    }

    cout << "Preorder : ";
    for(auto x : pre){
        cout << x << " ";
    }

    cout << "Inorder : ";
    for (auto x : in)
    {
        cout << x << " ";
    }

    cout << "Postorder : ";
    for (auto x : post)
    {
        cout << x << " ";
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}