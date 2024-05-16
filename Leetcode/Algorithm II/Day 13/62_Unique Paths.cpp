class Solution {
public:
    int func(int row, int col, int &m, int &n, vector<vector<int>> &dp)
    {
            if(dp[row][col]!=-1)
            return dp[row][col];
            else if(row==m-1 && col==n-1)
            return dp[row][col]=1;
            int count=0;
            if(col+1<n)
            count+=func(row,col+1,m,n,dp);
            if(row+1<m)
            count+=func(row+1,col,m,n,dp);
            return dp[row][col]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,0,m,n,dp);
    }
};
