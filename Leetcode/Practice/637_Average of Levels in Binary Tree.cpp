class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        int len,n;
        long long sum;
        TreeNode* cur;
        while(!q.empty())
        {
            len=n=q.size();
            sum=0;
            while(n--)
            {
                cur=q.front();
                sum+=cur->val;
                q.pop();
                if(cur->left)
                q.push(cur->left);
                if(cur->right)
                q.push(cur->right);
            }
            ans.push_back(sum/(double)len);
        }
        return ans;
    }
};
