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
    void dfs(TreeNode* root, long long num,long long &sum)
    {
        num=(num*10)+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=num;
            return;
        }
        if(root->left!=NULL)
        dfs(root->left,num,sum);
        if(root->right!=NULL)
        dfs(root->right,num,sum);
    }
    int sumNumbers(TreeNode* root) {
        long long num=0,sum=0;
        dfs(root,num,sum);
        return sum;
    }
};
//or
class Solution {
public:
    void dfs(TreeNode* root, vector<long long> &v, long long num)
    {
        num=(num*10)+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(num);
            return;
        }
        if(root->left!=NULL)
        dfs(root->left,v,num);
        if(root->right!=NULL)
        dfs(root->right,v,num);
    }
    int sumNumbers(TreeNode* root) {
        vector<long long> v;
        int num=0;
        dfs(root,v,num);
        num=0;
        for(long long &it: v)
        num+=it;
        return num;
    }
};
