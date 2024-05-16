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
class Solution {
public:
    void func(TreeNode* root, int val)
    {
        if(root!=NULL && root->left==NULL && root->val>val)
        {
            root->left= new TreeNode(val);
        }
        else if(root!=NULL && root->right==NULL && root->val<val)
        {
            root->right= new TreeNode(val);
        }
        if(root!=NULL)
        {
            if(root->val>val)
            func(root->left,val);
            else func(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            root= new TreeNode(val);
            return root;
        }
        func(root,val);
        return root;
    }
};
