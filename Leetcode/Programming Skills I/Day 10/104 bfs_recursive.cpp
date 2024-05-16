#include<bits/stdc++.h>
using namespace std;

class TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	{val=0; left=NULL; right=NULL;}
	TreeNode(int x)
	{val=x; left=NULL; right=NULL;}
	TreeNode(int x, TreeNode* l, TreeNode* r)
	{val=x; left=l; right=r;}
};

int dfs(TreeNode* x)
{
    int l_dfs=0, r_dfs=0,mx;
    if(x->left!=nullptr)
    {
        l_dfs=dfs(x->left);
    }
    
    if(x->right!=nullptr)
    {
        r_dfs=dfs(x->right);
    }
    if(x->left==nullptr && x->right==nullptr)
    return 0;
    else
    {
        if(l_dfs>=r_dfs)
        mx=l_dfs+1;
        else
        mx=r_dfs+1;
        return mx;
    }
}
//recursive way same, shortcut
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {   
//        if(root==NULL) return 0;
//        else return(1+max(maxDepth(root->right),maxDepth(root->left)));
//    }
//};
class Solution {
public:
    int maxDepth(TreeNode* root) {
            if(root==nullptr)
            return 0;
            int count=0;
            TreeNode* temp=root;
            int lvl=dfs(temp)+1;
            return lvl;
    }
};

int main()
{
	
	return 0;
}
