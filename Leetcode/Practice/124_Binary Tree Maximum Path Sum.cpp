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
int mx=INT_MIN;
	int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int total=l+r+root->val;
        int any=root->val+max(l,r);
        mx=max({mx,total,any,root->val});
        return max(any,root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
