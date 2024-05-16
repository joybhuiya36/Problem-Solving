class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        return 0;
        if(m>1 && n>1)
        if(grid[m-2][n-1]==1 && grid[m-1][n-2]==1)
        return 0;
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i=m-1;i>=0;i--)
        {
            if(grid[i][n-1]==0)
            dp[i][n-1]=1;
            else break;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(grid[m-1][i]==0)
            dp[m-1][i]=1;
            else break;
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(grid[i][j]==1)
                continue;
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
