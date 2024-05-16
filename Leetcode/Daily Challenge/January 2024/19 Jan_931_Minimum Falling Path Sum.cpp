class Solution {
public:
const int val=-999999;
    int dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp, int &n)
    {
        if(row==n)
        return 0;
        if(dp[row][col]!=val)
        return dp[row][col];
        int mn=INT_MAX;
        if(col>0)
        mn=min(mn,dfs(row+1,col-1,mat,dp,n));
        mn=min(mn,dfs(row+1,col,mat,dp,n));
        if(col<n-1)
        mn=min(mn,dfs(row+1,col+1,mat,dp,n));
        return dp[row][col]=mn+mat[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size(), mn=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,val));
        for(int i=0;i<n;i++)
        {
            mn=min(mn,dfs(0,i,mat,dp,n));
        }
        return mn;
    }
};
