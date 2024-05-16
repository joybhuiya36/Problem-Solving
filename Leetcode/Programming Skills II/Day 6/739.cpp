class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack< pair<int,int> > stk;
        vector<int> ans(tem.size(),0),v;
        for(int i=0;i<tem.size();i++)
        {
            while(!stk.empty() && tem[i]>stk.top().first)
            {
                ans[stk.top().second]=i-stk.top().second;
                stk.pop();
            }
            stk.push({tem[i],i});
        }
        return ans;
    }
};
