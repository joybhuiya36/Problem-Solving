/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct parent {
    TreeNode *node;
    parent *p;
    parent(TreeNode* x)
    {
        node=x;
        p=NULL;
    }
    parent(TreeNode* x, parent* y)
    {
        node=x;
        p=y;
    }
 };
    void dfs(parent* root, int &target, parent*& ans)
    {
        if(root->node->val==target)
        {
            ans=root;
        }
        if(root->node->left)
        {
            parent* lf=new parent(root->node->left,root);
            dfs(lf,target,ans);
        }
        if(root->node->right)
        {
            parent* rt=new parent(root->node->right,root);
            dfs(rt,target,ans);
        }
    }
    void finder(TreeNode* root, int k, parent* rt, vector<int> &v, vector<int> &visit)
    {
        if(visit[root->val]==1)
        return;
        if(k==0)
        {
            v.push_back(root->val);
            return;
        }
        visit[root->val]=1;
        if(rt && rt->p)
        finder(rt->p->node,k-1,rt->p,v,visit);
        if(root->left)
        finder(root->left,k-1,NULL,v,visit);
        if(root->right)
        finder(root->right,k-1,NULL,v,visit);
    }
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent *ob=new parent(root);
        parent *cur;
        dfs(ob,target->val,cur);
        vector<int> v;
        vector<int> visit(501,0);
        finder(cur->node,k,cur,v,visit);
        return v;
    }
};
