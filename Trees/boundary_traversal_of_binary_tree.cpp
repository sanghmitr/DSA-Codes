//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree

class Solution {
public:
    bool isLeaf(Node *root)
    {
        if(root == NULL)
            return false;
        if(root->left == NULL and root->right == NULL)
            return true;
        return false;
    }
    void leftBoundary(Node *root, vector<int>&ans)
    {
        Node *temp = root->left;
        while(temp)
        {
            if(!isLeaf(temp))
                ans.push_back(temp->data);
            if(temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    
    void leafNodes(Node *root, vector<int>&ans)
    {
        if(root == NULL)
            return;
        
        if(isLeaf(root))
            ans.push_back(root->data);
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }
    void rightBoundary(Node *root, vector<int>&ans)
    {
        Node *temp = root->right;
        vector<int>v;
        while(temp)
        {
            if(!isLeaf(temp))
                v.push_back(temp->data);
            if(temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        reverse(v.begin(), v.end());
        ans.insert(ans.end(), v.begin(), v.end());
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root == NULL)
            return ans;
        
        if(!isLeaf(root))
            ans.push_back(root->data);
            
        leftBoundary(root, ans);
        leafNodes(root, ans);
        rightBoundary(root, ans);
        return ans;
    }
};