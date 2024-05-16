//DP
//Memorization
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
//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        dp[i][n-1]=1;
        for(int i=0;i<n;i++)
        dp[m-1][i]=1;
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
