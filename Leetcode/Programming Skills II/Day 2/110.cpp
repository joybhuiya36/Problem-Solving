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
    int func(TreeNode* root, bool &checker)
    {
        if(!root)
        return 0;
        int ll=func(root->left,checker);
        int rr=func(root->right,checker);
        if(abs(ll-rr)!=1 && abs(ll-rr)!=0)
        checker=false;
        return max(ll,rr)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool checker=true;
        func(root,checker);
        return checker;
    }
};
