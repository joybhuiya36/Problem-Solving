class Solution {
public:
map<pair<int,int>,vector<TreeNode*>> dp;
    vector<TreeNode*> builder(int l, int r)
    {
        if(l>r) return {NULL};
        if(dp.count({l,r}))
        return dp[{l,r}];
        vector<TreeNode*> v;
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for(int i=l;i<=r;i++)
        {
            left=builder(l,i-1);
            right=builder(i+1,r);
            for(auto &ll:left)
            {
                for(auto &rr:right)
                {
                    v.push_back(new TreeNode(i,ll,rr));
                }
            }
        }
        return dp[{l,r}]=v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return builder(1,n);
    }
};
