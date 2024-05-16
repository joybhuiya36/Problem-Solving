/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//My solution by double dfs and matching the ancestor
class Solution {
public:
    vector<int> func(TreeNode* root, int t, vector<int> &v)
    {
        if(root->val==t)
        {
            v.push_back(root->val);
            return v;
        }
        else if(root->val>t)
        {
            v.push_back(root->val);
            if(root->left)
            return func(root->left,t,v);
        }
        else if(root->val<t)
        {
            v.push_back(root->val);
            if(root->right)
            return func(root->right,t,v);
        }
        return v;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        func(root,p->val,v1);
        func(root,q->val,v2);
        int n;
        int loop=min(v1.size(),v2.size());
        for(int i=0;i<loop;i++)
        {
            if(v1[i]==v2[i])
            n=v1[i];
            else break;
        }
        TreeNode* tree=new TreeNode(n);
        return tree;
    }
};
//Another solution by matching both two value with root
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left, p, q);
        else if(root->val<p->val && root->val<q->val)
        return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
