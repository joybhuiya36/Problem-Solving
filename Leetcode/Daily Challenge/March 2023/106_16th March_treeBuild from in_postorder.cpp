class Solution {
public:
    unordered_map<int,int> mp;
    int postSize;
    TreeNode* treeBuilder(vector<int>& post, int l, int r)
    {
        if(l>r) return NULL;
        int rootval=post[postSize--];
        int rootidx=mp[rootval];
        TreeNode* root= new TreeNode(rootval);
        root->right=treeBuilder(post,rootidx+1,r);
        root->left=treeBuilder(post,l,rootidx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++)
        mp[in[i]]=i;
        postSize=post.size()-1;
        return treeBuilder(post,0,in.size()-1);
    }
};
