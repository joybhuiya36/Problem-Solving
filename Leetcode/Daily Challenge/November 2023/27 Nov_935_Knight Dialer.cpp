class Solution {
public:
int mod=1e9+7;
vector<vector<int>> adj={
    {4,6},
    {6,8},
    {7,9},
    {4,8},
    {3,9,0},
    {},
    {1,7,0},
    {2,6},
    {1,3},
    {2,4}
};
int dp[5001][10];
	int solve(int n, int d)
    {
        if(n==0)
        return 1;
        if(dp[n][d]!=-1)
        return dp[n][d];
        int ans=0;
        for(auto &nxt:adj[d])
        {
            ans=(ans+solve(n-1,nxt))%mod;
        }
        return dp[n][d]=ans;
    }
    int knightDialer(int n) {
        int ans=0;
        for(int i=0;i<5001;i++)
        {
            for(int j=0;j<10;j++)
            dp[i][j]=-1;
        }
        for(int i=0;i<10;i++)
        ans=(ans+solve(n-1,i))%mod;
        return ans;
    }
};
