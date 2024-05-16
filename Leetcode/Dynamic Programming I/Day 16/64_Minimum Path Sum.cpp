//DP
//Tabulation (Python)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        for i in range(m-2,-1,-1):
            grid[i][n-1]+=grid[i+1][n-1]
        for i in range(n-2,-1,-1):
            grid[m-1][i]+=grid[m-1][i+1]
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                grid[i][j]+=min(grid[i][j+1],grid[i+1][j])
        return grid[0][0]
//Memorization
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
        right=func(row,col+1,grid);
        if(row<m-1)
        down=func(row+1,col,grid);
        return dp[row][col]=grid[row][col]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return func(0,0,grid);
    }
};
