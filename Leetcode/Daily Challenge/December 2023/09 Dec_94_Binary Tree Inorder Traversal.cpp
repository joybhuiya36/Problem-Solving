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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> stk;
        TreeNode* cur=root;
        while(cur || !stk.empty())
        {
            while(cur!=NULL)
            {
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();
            v.push_back(cur->val);
            stk.pop();
            cur=cur->right;
        }
        return v;
    }
};
