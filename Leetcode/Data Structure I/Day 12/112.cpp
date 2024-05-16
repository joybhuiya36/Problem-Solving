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
    bool func(TreeNode* root, int t, int sum)
    {
        
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==t)
            return true;
            else return false;
        }
        bool ll,rr;
        if(root->left)
        ll=func(root->left,t,sum+root->left->val);
        if(root->right)
        rr=func(root->right,t,sum+root->right->val);
        return ll||rr;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
        return false;
        int sum=root->val;
        return func(root, targetSum, sum);
    }
};
