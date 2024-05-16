//DP
//Memorization
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
//Python
class Solution:
    def dfs(self, row, col, mat, dp, n) -> int:
        if row==n:
            return 0
        if dp[row][col]!=-2147483647:
            return dp[row][col]
        mn=2147483648
        if col>0:
            mn=min(mn,self.dfs(row+1,col-1,mat,dp,n))
        mn=min(mn,self.dfs(row+1,col,mat,dp,n))
        if col<n-1:
            mn=min(mn,self.dfs(row+1,col+1,mat,dp,n))
        dp[row][col]=mn+mat[row][col]
        return dp[row][col]
    def minFallingPathSum(self, mat: List[List[int]]) -> int:
        n=len(mat)
        INT_MAX=2147483648
        INT_MIN=-2147483647
        dp=[[INT_MIN]*n for _ in range(n)]
        ans=INT_MAX
        for i in range(n):
            ans=min(ans,self.dfs(0,i,mat,dp,n))
        return ans
//Tabulation
class Solution:
    def minFallingPathSum(self, mat: List[List[int]]) -> int:
        n=len(mat)
        ans=2147483648
        for i in range(1,n,1):
            for j in range(n):
                val=10001
                if j>0:
                    val=min(val,mat[i-1][j-1])
                val=min(val,mat[i-1][j])
                if j<n-1:
                    val=min(val,mat[i-1][j+1])
                mat[i][j]=mat[i][j]+val
        for i in range(n):
            ans=min(ans,mat[n-1][i])
        return ans
