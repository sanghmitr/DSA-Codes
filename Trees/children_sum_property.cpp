//https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos


void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL)
        return;
    
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    
    if(child >= root->data) root->data = child;
    else
    {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left != NULL or root->right != NULL)
        root->data = total;
 
}  