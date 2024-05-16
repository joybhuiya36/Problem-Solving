class Solution {
public:
int mod=1e9+7;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dp[51][51][51];
	int dfs(int i, int j, int mx, int &m, int &n)
    {
        if(i<0 || j<0 || i==m || j==n)
        return 1;
        if(mx==0)
        return 0;
        if(dp[i][j][mx]!=-1)
        return dp[i][j][mx];
        int sum=0;
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            sum=(sum+dfs(x,y,mx-1,m,n))%mod;
        }
        return dp[i][j][mx]=sum;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,maxMove,m,n);
    }
};
