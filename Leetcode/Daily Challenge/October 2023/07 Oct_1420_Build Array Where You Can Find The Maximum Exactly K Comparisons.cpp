class Solution {
public:
int mod=1e9+7;
int N,M,K;
int dp[51][51][101];
    int solve(int idx, int cost, int mx)
    {
        if(cost>K) return 0;
        if(idx==N)
        {
            if(cost==K)
                return 1;
            return 0;
        }
        if(dp[idx][cost][mx]!=-1) return dp[idx][cost][mx];
        int rslt=0;
        for(int i=1;i<=M;i++)
        {
            if(i>mx)
            rslt=(rslt+solve(idx+1,cost+1,i))%mod;
            else rslt=(rslt+solve(idx+1,cost,mx))%mod;
        }
        return dp[idx][cost][mx]=rslt;
    }
    int numOfArrays(int n, int m, int k) {
        N=n; M=m; K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, 0);
    }
};
