//InOrder Traversal
class Solution {
public:
    int getMinimumDifference(TreeNode* cur) {
        stack<TreeNode*> stk;
        int ans=1e9, pre=-1e5;
        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.emplace(cur);
                cur=cur->left;
            }
            cur=stk.top();
            stk.pop();
            ans=min(ans,cur->val-pre);
            pre=cur->val;
            cur=cur->right;
        }
        return ans;
    }
};
//DFS
class Solution {
public:
    void getVals(TreeNode *root, vector<int> &vals)
    {
        if (root)
            vals.push_back(root->val);
        if (root->left)
            getVals(root->left, vals);
        if (root->right)
            getVals(root->right, vals);
    }

    int getMinimumDifference(TreeNode* root) {
            vector<int> vals;
            getVals(root, vals);
            sort(vals.begin(), vals.end());
            int min_diff = INT_MAX;
            for (auto i = 0; i < vals.size() - 1; ++i)
                min_diff = min(vals[i + 1] - vals[i], min_diff);
            return min_diff;        
    }
};
