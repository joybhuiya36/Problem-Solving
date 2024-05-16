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
 
 //PreOrder Traversal

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
        return v;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            v.push_back(stk.top()->val);
            TreeNode* rt=stk.top();
            stk.pop();
            if(rt->right)
            stk.push(rt->right);
            if(rt->left)
            stk.push(rt->left);
        }
        return v;

    }
};
