class Solution {
public:
	bool dfs(TreeNode* p, TreeNode* q)
    {
        if(p==NULL)
        {
            if(q!=NULL)
            return false;
            else return true;
        }
        else if(q==NULL)
        {
            if(p!=NULL)
            return false;
            else return true;
        }
        else
        {
            if(p->val!=q->val)
            return false;
        }
        bool ch=true;
        ch&=dfs(p->left,q->left);
        ch&=dfs(p->right,q->right);
        return ch;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
//or
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return (p==q);
        }
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
