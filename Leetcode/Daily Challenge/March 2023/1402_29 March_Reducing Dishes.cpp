//Memorization
class Solution {
public:
vector<vector<int>> dp;
	int mx_likeTime(int idx, int time, vector<int> &sf, int &n)
    {
        if(idx>=n)
        return 0;
        if(dp[time-1][idx]!=-1)
        return dp[time-1][idx];
        int op1=time*sf[idx]+mx_likeTime(idx+1,time+1,sf,n);
        int op2=mx_likeTime(idx+1,time,sf,n);
        return dp[time-1][idx]=max(op1,op2);
    }
    int maxSatisfaction(vector<int>& sf) {
        int n=sf.size();
        dp.resize(n,vector<int>(n,-1));
        sort(sf.begin(),sf.end());
        return mx_likeTime(0,1,sf,n);
    }
};
//Tabulation
class Solution {
public:
    int maxSatisfaction(vector<int>& sf) {
        sort(sf.begin(),sf.end());
        int n=sf.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int time=1;time<=n;time++)
            {
                int op1=sf[idx]*time+dp[idx+1][time+1];
                int op2=dp[idx+1][time];
                dp[idx][time]=max(op1,op2);
            }
        }
        return dp[0][1];
    }
};
