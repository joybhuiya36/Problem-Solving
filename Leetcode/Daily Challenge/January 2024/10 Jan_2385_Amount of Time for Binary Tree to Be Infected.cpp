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
struct node {
    int val;
    vector<node*> child;
    node(int x): val(x) {}
};
class Solution {
public:
node *src,*left,*right;
	void dfs(TreeNode* root, int t, node *parent, node* cur)
    {
        if(root->val==t)
        {
            src= cur;
        }
        if(parent) cur->child.push_back(parent);
        if(root->left)
        {
            left=new node(root->left->val);
            cur->child.push_back(left);
        	dfs(root->left,t,cur,left);
        }
        if(root->right)
        {
            right=new node(root->right->val);
            cur->child.push_back(right);
        	dfs(root->right,t,cur,right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        node* tmp=NULL;
        node* cur=new node(root->val);
        dfs(root,start,tmp,cur);
        queue<node*> q;
        q.push(src);
        int n,m,l=0;
        unordered_set<int> visit;
        visit.insert(src->val);
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                cur=q.front();
                q.pop();
                m=cur->child.size();
                for(int i=0;i<cur->child.size();i++)
                {
                    right=cur->child[i];
                    if(!visit.count(right->val))
                    {
                        q.push(right);
                        visit.insert(right->val);
                    }
                }
            }
            l++;
        }
        return l-1;
    }
};
