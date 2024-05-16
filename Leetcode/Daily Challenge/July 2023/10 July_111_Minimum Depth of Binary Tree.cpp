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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int n,lvl=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                root=q.front();
                q.pop();
                if(root->left==NULL && root->right==NULL)
                return lvl;
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
            lvl++;
        }
        return lvl;
    }
};
