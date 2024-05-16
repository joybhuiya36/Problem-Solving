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
 //InOrder Traversal for Binary Search Tree(BST) Checker
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        long long pre=-3147483648;
        while(cur || !stk.empty())
        {
            while(cur!=NULL)
            {
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();
            stk.pop();
            if(cur->val>pre)
            pre=cur->val;
            else return false;
            cur=cur->right;
        }
        return true;
    }
};
//PreOrder Traversal (each node should be in a range, min-max)
class Solution {
public:
    bool func(TreeNode* root, long long mn, long long mx)
    {
        if(root==NULL)
        return true;
        else if(root->val>=mx || root->val<=mn)
        return false;
        return func(root->left,mn,root->val) && func(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        long long mn=-3147483648, mx=3147483648;
        return func(root,mn,mx);
    }
};
