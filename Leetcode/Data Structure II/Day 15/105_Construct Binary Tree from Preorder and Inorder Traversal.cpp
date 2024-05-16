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
unordered_map<int,int> mp;
	TreeNode* treeBuilder(int l, int r, int idx, vector<int> &pre)
    {
        if(l==r) return new TreeNode(pre[idx]);
        TreeNode* root=new TreeNode(pre[idx]);
        int ptr=mp[pre[idx]];
        int newIdx=ptr-l+idx+1;
        if(ptr-1>=l)
        root->left=treeBuilder(l,ptr-1,idx+1,pre);
        if(ptr+1<=r)
        root->right=treeBuilder(ptr+1,r,newIdx,pre);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++)
        mp[in[i]]=i;
        return treeBuilder(0,in.size()-1,0,pre);
    }
};
