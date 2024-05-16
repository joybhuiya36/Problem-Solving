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
    void dfs(TreeNode* root, bool left, int count)
    {
        
        if(root==NULL)
        {
            mx=max(mx,count-1);
            return;
        }
        if(left==false)
        {
            dfs(root->left,true,count+1);
            dfs(root->right,false,1);
        }
        else
        {
            dfs(root->right,false,count+1);
            dfs(root->left,true,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,false,0);
        dfs(root,true,0);
        return mx;
    }
};
