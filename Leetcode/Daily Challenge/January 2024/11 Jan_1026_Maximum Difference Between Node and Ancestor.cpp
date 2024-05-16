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
int mx=0;
void dfs(TreeNode *root, int pmax, int pmin)
{
    if(!root)
    return;
    mx=max({mx,abs(pmax-root->val),abs(pmin-root->val)});
    dfs(root->left,max(root->val,pmax),min(root->val,pmin));
    dfs(root->right,max(root->val,pmax),min(root->val,pmin));
}
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return mx;
    }
};
