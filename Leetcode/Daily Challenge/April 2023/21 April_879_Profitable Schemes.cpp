class Solution {
public:
int dp[101][101][101];
int mod=1e9+7;
	int solve(int idx, int members, int profit, int &n, int &minp, vector<int> &gp, vector<int> &prft)
    {
        if(idx==gp.size())
        return profit>=minp;
        if(dp[idx][members][profit]!=-1)
        return dp[idx][members][profit];
        int totalways=solve(idx+1,members,profit,n,minp,gp,prft);
        if(members+gp[idx]<=n)
        totalways+=solve(idx+1,members+gp[idx],min(minp,profit+prft[idx]),n,minp,gp,prft);
        return dp[idx][members][profit]=totalways%mod;
    }
    int profitableSchemes(int n, int minp, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minp,group,profit);
    }
};
