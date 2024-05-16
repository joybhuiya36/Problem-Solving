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
void dfs(TreeNode* x, int &sum)
{
    if(x->left!=nullptr)
    {
        if(x->left->left==nullptr && x->left->right==nullptr)
        sum+=x->left->val;
        dfs(x->left,sum);
    }
    if(x->right!=nullptr)
    dfs(x->right,sum);

}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* temp=root;
        if(temp->left==nullptr && temp->right==nullptr)
        return 0;
        int sum=0;
        dfs(temp,sum);
        return sum;
    }
};

int main()
{
	
	return 0;
}
