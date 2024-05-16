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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        int sum=0;
        while(!st.empty() || cur!=NULL)
        {
            while(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            if(cur->val>=low)
            {
                sum+=cur->val;
                if(cur->val==high)
                return sum;
            }
            cur=cur->right;
        }
        return sum;
    }
};
