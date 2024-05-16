//DP
//Memorization
class Solution {
public:
    int func(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &dp, int &m, int &n)
    {
        if(row==m || col==n)
        return 0;
        if(mat[row][col]=='0')
        return dp[row][col]=0;
        if(dp[row][col]!=-1)
        return dp[row][col];
        return dp[row][col]=1+min(func(row,col+1,mat,dp,m,n), min(func(row+1,col,mat,dp,m,n),func(row+1,col+1,mat,dp,m,n)));
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,func(i,j,mat,dp,m,n));
            }
        }
        return ans*ans;
    }
};
//Tabulation
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(mat[i][n-1]=='1')
            ans=1;
            dp[i][n-1]=mat[i][n-1]-'0';
        }
        for(int i=0;i<n;i++)
        {
            if(mat[m-1][i]=='1')
            ans=1;
            dp[m-1][i]=mat[m-1][i]-'0';
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(mat[i][j]=='0')
                continue;
                dp[i][j]=1+min(dp[i+1][j], min(dp[i][j+1],dp[i+1][j+1]));
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};
//Space Optimization
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        vector<int> dp(n,0);
        vector<int> cur(n,0);
        for(int i=0;i<n;i++)
        {
            if(mat[m-1][i]=='1')
            {
                dp[i]=1;
                ans=1;
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            cur[n-1]=mat[i][n-1]-'0';
            if(cur[n-1]==1)
            ans=max(ans,cur[n-1]);
            for(int j=n-2;j>=0;j--)
            {
                if(mat[i][j]=='0')
                {
                    cur[j]=0;
                    continue;
                }
                cur[j]=1+min(dp[j], min(cur[j+1],dp[j+1]));
                ans=max(ans,cur[j]);
            }
            dp=cur;
        }
        return ans*ans;
    }
};
//Python
class Solution:
    def maximalSquare(self, mat: List[List[str]]) -> int:
        m=len(mat)
        n=len(mat[0])
        sum=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1,1):
            for j in range(1,n+1,1):
                sum[i][j]=int(mat[i-1][j-1])+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
        limit=min(m,n)
        ans=0
        flag=0
        for k in range(limit):
            for i in range(m):
                if i+k>m-1:
                    break
                x1=i
                x2=i+k
                for j in range(n):
                    if j+k>n-1:
                        break
                    y1=j
                    y2=j+k
                    sq=sum[x2+1][y2+1]-sum[x1][y2+1]-sum[x2+1][y1]+sum[x1][y1]
                    if sq==(k+1)**2:
                        ans=sq
                        flag=1
                        break
                if flag==1:
                    flag=0
                    break
        return ans
        
