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
void invertTree(TreeNode* root, int n) {
        if(!root) return;
        TreeNode* ex=root->left;
        root->left=root->right;
        root->right=ex;
        invertTree(root->left,n);
        invertTree(root->right,n);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp=root;
        invertTree(root,0);
        return temp;
    }
};
