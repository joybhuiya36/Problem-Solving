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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        v.push_back(root->val);
        int n,f,mx;
        while(!q.empty())
        {
            n=q.size();
            f=0; mx=INT_MIN;
            while(n--)
            {	
                root=q.front();
            	q.pop();
                if(root->left)
                {
                	q.push(root->left);
                	f=1;
                    mx=max(mx,root->left->val);
                }
                if(root->right)
                {
                    q.push(root->right);
                    f=1;
                    mx=max(mx,root->right->val);
                }
            }
            if(f==1)
            v.push_back(mx);
        }
        return v;
    }
};
