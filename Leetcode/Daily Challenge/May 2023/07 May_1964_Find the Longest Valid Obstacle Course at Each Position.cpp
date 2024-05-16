class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n=ob.size();
        vector<int> v;
        vector<int> ans(n);
        int idx;
        for(int i=0;i<n;i++)
        {
            idx=upper_bound(v.begin(),v.end(),ob[i])-v.begin();
            if(idx==v.size())
            {
                v.push_back(ob[i]);
            }
            else
            {
                v[idx]=ob[i];
            }
            ans[i]=idx+1;
        }
        return ans;
    }
};
//DP (TLE)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n=ob.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(ob[j]<=ob[i])
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        return dp;
    }
};
