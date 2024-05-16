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
    TreeNode* treeBuilder(int l, int r, vector<int> &nums)
    {
        if(l==r)
        return new TreeNode(nums[l]);
        int mid=((r-l)/2)+l;
        TreeNode* root=new TreeNode(nums[mid]);
        if(mid-1>=l)
        root->left=treeBuilder(l,mid-1,nums);
        if(mid+1<=r)
        root->right=treeBuilder(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return treeBuilder(0,nums.size()-1,nums);
    }
};
