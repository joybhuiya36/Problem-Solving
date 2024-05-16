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
int n=0, flag;
int arr[10];
    bool checkPalin()
    {
        flag=0;
        for(int i=1;i<10;i++)
        {
            if(arr[i]%2==1)
            flag++;
            if(flag>1)
            return false;
        }
        return true;
    }
    void dfs(TreeNode* root)
    {
        if(!root) return;
        arr[root->val]++;
        if(!root->left && !root->right)
        {
            if(checkPalin())
            n++;
            arr[root->val]--;
            return;
        }
        dfs(root->left);
        dfs(root->right);
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        memset(arr,0,sizeof(arr));
        dfs(root);
        return n;
    }
};
