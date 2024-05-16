class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size(),j;
        stack<int> stk;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && tem[i]>tem[stk.top()])
            {
                j=stk.top();
                ans[j]=i-j;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
