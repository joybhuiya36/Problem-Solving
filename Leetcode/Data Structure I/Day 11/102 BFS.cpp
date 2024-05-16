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
 
 //(2D vector push_back different system)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty())
        {
            int n=q.size();
            v.push_back({});
            while(n--)
            {
                root=q.front();
                q.pop();
                v[i].push_back(root->val);
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
            i++;
        }
        return v;
    }
};
//or
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v2;
            while(n--)
            {
                root=q.front();
                q.pop();
                v2.push_back(root->val);
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
            v.push_back(v2);
        }
        return v;
    }

