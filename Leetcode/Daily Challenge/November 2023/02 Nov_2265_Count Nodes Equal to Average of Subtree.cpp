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
int n=0;
	vector<int> func(TreeNode* root)
    {
        if(!root)
        return {0,0};
        auto l=func(root->left);
        auto r=func(root->right);
        int sum=l[0]+r[0]+root->val;
        int c=l[1]+r[1]+1;
        if(sum/c==root->val) n++;
        return {sum,c};
    }
    int averageOfSubtree(TreeNode* root) {
        func(root);
        return n;
    }
};
