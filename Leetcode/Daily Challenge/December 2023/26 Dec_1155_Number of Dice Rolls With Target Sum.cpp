class Solution {
public:
int kk, mod=1e9+7;
int dp[31][1001]={0};
	int solve(int n, int t)
    {
        if(n<0 || n*kk<t || t<0)
        return 0;
        if(n==0)
        {
            if(t==0)
            return 1;
            return 0;
        }
        if(dp[n][t]!=0)
        return dp[n][t];
        int ans=0;
        for(int i=1;i<=kk;i++)
        {
            if(t<n) break;
            ans=(ans+solve(n-1,t-i))%mod;
        }
        return dp[n][t]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(n*k<target) return 0;
        kk=k;
        return solve(n, target);
    }
};
