//BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        int n,flag=0;
        q.push(root);
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                root=q.front();
                q.pop();
                if(flag==1 && root->left!=NULL)
                return false;
                if(root->right==NULL)
                flag=1;
                else if(root->left==NULL && root->right!=NULL)
                return false;
                if(root->left)
                q.push(root->left);
                if(root->right)
                q.push(root->right);
            }
        }
        return true;
    }
};
//DFS
class Solution {
public:
    void dfs(TreeNode* root, bool &checker, int lvl, int &cup, int &flag)
    {
        if(checker)
        {
            if(root==NULL)
            {
                if(cup==-1)
                cup=lvl;
                else if(cup<lvl)
                checker=false;
                else if(cup-lvl==1)
                flag=1;
                else if(flag && cup==lvl)
                checker=false;
                if(cup-lvl>1)
                checker=false;
                return;
            }
            dfs(root->left,checker,lvl+1,cup,flag);
            dfs(root->right,checker,lvl+1,cup,flag);
        }

    }
    bool isCompleteTree(TreeNode* root) {
        int cup=-1,flag=0;
        bool checker=true;
        dfs(root,checker,0,cup,flag);
        return checker;
    }
};
