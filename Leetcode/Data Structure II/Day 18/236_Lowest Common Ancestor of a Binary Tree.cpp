//optimal Solution (if root==p/q return true/root)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
        return root;
        if(root->left==NULL && root->right==NULL)
        return NULL;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right)
        return root;
        else if(!left) return right;
        else return left;
    }
};
//My Solution by comparing sequence of two vector
class Solution {
public:
vector<int> v,pv,qv;
    void dfs(TreeNode* root, int &p, int &q)
    {
        if(root->val==p)
        pv=v;
        else if(root->val==q)
        qv=v;
        if(root->left)
        {
            v.emplace_back(root->left->val);
            dfs(root->left,p,q);
            v.pop_back();
        }
        if(root->right)
        {
            v.emplace_back(root->right->val);
            dfs(root->right,p,q);
            v.pop_back();
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        v.emplace_back(root->val);
        dfs(root,p->val,q->val);
        int n,val;
        pv.size()<=qv.size()? n=pv.size() : n=qv.size();
        for(int i=0;i<n;i++)
        if(pv[i]==qv[i]) val=pv[i];
        return new TreeNode(val);
    }
};
