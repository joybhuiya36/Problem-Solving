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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long mod=4294967295;
        queue<pair<TreeNode*,unsigned long>> q;
        pair<TreeNode*,unsigned long> cur;
        unsigned long startFlag, endFlag, width;
        q.push({root,1});
        int n;
        while(q.size())
        {
            n=q.size();
            startFlag=0;
            endFlag=0;
            while(n--)
            {
                cur=q.front();
                q.pop();
                if(startFlag==0)
                startFlag=cur.second;
                endFlag=cur.second;
                if(cur.first->left)
                q.push({cur.first->left,(cur.second*2-1)%mod});
                if(cur.first->right)
                q.push({cur.first->right,(cur.second*2)%mod});
            }
            width=max(width,endFlag-startFlag+1);
        }
        return width;
    }
};
