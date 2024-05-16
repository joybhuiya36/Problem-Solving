class Solution {
public:
int dp[100001][2][101];
	int solve(int idx, vector<int> &p, int buy, int t, int &n)
    {
        if(t==0)
        return 0;
        if(idx==n)
        return 0;
        if(dp[idx][buy][t]!=-1)
        return dp[idx][buy][t];
        int sell=0,skip=0,taken=0;
        if(buy)
        sell=p[idx]+solve(idx+1,p,!buy,t-1,n);
        else
        taken=-p[idx]+solve(idx+1,p,!buy,t,n);
        skip=solve(idx+1,p,buy,t,n);
        return dp[idx][buy][t]=max({sell,skip,taken});
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,0,k,n);
    }
};
