/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //Binary Search Tree with DFS
class Solution {
public:
    TreeNode* func(TreeNode* root, int val)
    {
        if(root==NULL)
        return NULL;
        else if(root->val==val)
        return root;
        TreeNode* ll=func(root->left,val);
        TreeNode* rr=func(root->right,val);
        if(ll!=NULL)
        return ll;
        else if(rr!=NULL)
        return rr;
        else return NULL;
    
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return func(root,val);
    }
};
//Normal DFS
class Solution {
public:
    TreeNode* func(TreeNode* root, int val)
    {
        if(root==NULL)
        return NULL;
        else if(root->val==val)
        return root;
        TreeNode* ll=func(root->left,val);
        TreeNode* rr=func(root->right,val);
        if(ll!=NULL)
        return ll;
        else if(rr!=NULL)
        return rr;
        else return NULL;
    
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return func(root,val);
    }
};
