class Solution {
public:
int n,mod=1e9+7;
int dp[501][501];
	int solve(int i, int steps)
    {
        if(i<0 || i>=n) return 0;
        if(steps==0)
        return i==0;
        if(dp[i][steps]!=-1) return dp[i][steps];
        int rslt=0;
        rslt=solve(i-1,steps-1);
        rslt=(rslt+solve(i+1,steps-1))%mod;
        rslt=(rslt+solve(i,steps-1))%mod;
        return dp[i][steps]=rslt;
    }
    int numWays(int steps, int arrLen) {
        n=min(arrLen, ((steps/2)+1));
        memset(dp,-1,sizeof(dp));
        return solve(0,steps);
    }
};
