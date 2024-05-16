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
 
 //PostOrder Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    if(root==NULL) return v;
    stack<TreeNode*> stk;
    TreeNode* node;
    stk.push(root);
    while(!stk.empty())
    {
        node=stk.top();
        stk.pop();
        v.push_back(node->val);
        if(node->left)
        stk.push(node->left);
        if(node->right)
        stk.push(node->right);
    }
    reverse(v.begin(),v.end());
    return v;
    }
};
