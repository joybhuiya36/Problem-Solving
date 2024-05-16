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
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> v;
        int c=0,mx=0,pmx=INT_MIN;
        while(!stk.empty() || root!=NULL)
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(root->val!=pmx)
            {
                if(c!=0 && c>=mx)
                {
                    if(c>mx)
                    {
                        while(v.size()>0)
                        v.pop_back();
                    }
                    v.push_back(pmx);
                }
                mx=max(mx,c);
                c=1;
                pmx=root->val;
            }
            else c++;
            root=root->right;
        }
        if(c>=mx)
        {
            if(c>mx)
            {
                while(v.size()>0)
                v.pop_back();
            }
            v.push_back(pmx);
        }
        return v;
    }
};
