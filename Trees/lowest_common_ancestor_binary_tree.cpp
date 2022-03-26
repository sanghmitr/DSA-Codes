//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p)
            return p;
        if(root == q)
            return q;
        
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if(l == NULL and r == NULL)
            return NULL;
        if(l == NULL ^ r == NULL)
            return (l==NULL)? r : l;
        
        return root;
    }
};

//With extra space by finding root to node path and comparing their paths

// O(N) time and O(N) space solution
class Solution {
public:
    bool pathRootToNode(TreeNode *root, int target, vector<TreeNode*>&ans)
    {
        if(root == NULL)
            return false;

        ans.push_back(root);
        if(root->left == NULL and root->right == NULL and root->val != target)
        {   
            ans.pop_back();
            return false;
        }
        if(root->val == target)
        {
            return true;
        }

        bool l = pathRootToNode(root->left, target, ans);
        bool r = pathRootToNode(root->right, target, ans);
        if(l or r)
            return true;

        if(!ans.empty())
            ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        pathRootToNode(root, p->val, a);
        pathRootToNode(root, q->val, b);
        
        int i = 0;
        TreeNode* last = root;
        while(i < a.size() and i < b.size())
        {
            if(a[i] != b[i])
                break;
            else
                last = a[i];
            i++;
        }
        return last;
    }
};