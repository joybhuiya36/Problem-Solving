class Solution {
public:
int m,n,right,down;
vector<vector<int>> dp;
    int func(int row, int col, vector<vector<int>> &grid)
    {
        if(dp[row][col]!=-1)
        return dp[row][col];
        if(row==m-1 && col==n-1)
        {
            dp[row][col]=grid[row][col];
            return dp[row][col];
        }
        int right=500001, down=500001;
        if(col<n-1)
        right=grid[row][col]+func(row,col+1,grid);
        if(row<m-1)
        down=grid[row][col]+func(row+1,col,grid);
        return dp[row][col]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return func(0,0,grid);
    }
};
