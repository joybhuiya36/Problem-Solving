class Solution {
public:
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int mod=1e9+7;
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int &m, int &n)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        int result=1;
        for(int k=0;k<4;k++)
        {
            int ii=dir[k][0]+i;
            int jj=dir[k][1]+j;
            if(ii>=0 && jj>=0 && ii<m && jj<n && grid[i][j]>grid[ii][jj])
            result=(result+solve(ii,jj,grid,dp,m,n))%mod;
        }
        return dp[i][j]=result;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=(ans+solve(i,j,grid,dp,m,n))%mod;
            }
        }
        return ans;
    }
};
