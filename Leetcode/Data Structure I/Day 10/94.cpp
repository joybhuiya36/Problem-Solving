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
 
 //Geeks Inorder Traversal
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
//My first Inorder try
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* cur=root;
        while(!stk.empty())
        {
            if(cur->left!=NULL)
            {
                cur=cur->left;
                stk.push(cur);
            }
            else
            {
                rt:
                v.push_back(cur->val);
                TreeNode* pp= cur;
                stk.pop();
                if(pp->right!=NULL)
                {
                    cur=pp->right;
                    stk.push(cur);
                }
                else if (!stk.empty())
                {
                    cur=stk.top();
                    goto rt;
                }
            }
        }
        return v;
    }
};
