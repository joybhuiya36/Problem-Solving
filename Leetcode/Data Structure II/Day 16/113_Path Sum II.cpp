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
vector<vector<int>> ans;
vector<int> v;
    void backtrack(TreeNode* root, int &target, int sum)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
            ans.push_back(v);
            return;
        }
        if(root->left)
        {
            v.push_back(root->left->val);
            backtrack(root->left,target,sum+root->left->val);
            v.pop_back();
        }
        if(root->right)
        {
            v.push_back(root->right->val);
            backtrack(root->right,target,sum+root->right->val);
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return {};
        v.push_back(root->val);
        backtrack(root,targetSum,root->val);
        return ans;
    }
};
