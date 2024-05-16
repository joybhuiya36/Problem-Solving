//DP
//Tabulation
//Python
class Solution:
    def minimumTotal(self, tri: List[List[int]]) -> int:
        m=len(tri)
        for i in range(1,m,1):
            n=len(tri[i])
            for j in range(n):
                val=999999999
                if j>0:
                    val=min(val,tri[i-1][j-1])
                if j<n-1:
                    val=min(val,tri[i-1][j])
                tri[i][j]=tri[i][j]+val
        ans=999999999
        for i in range(len(tri[m-1])):
            ans=min(ans,tri[m-1][i])
        return ans
//or
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [0] *(len(triangle)+1)
        for i in triangle[::-1]:
            for j,n in enumerate(i):
                dp[j] = n + min(dp[j],dp[j+1])
        return dp[0]
//Memorization
class Solution {
public:
vector<vector<int>> dp;
    int func(int row, int col, vector<vector<int>>& tri)
    {
        if(row==tri.size())
        return 0;
        if(dp[row][col]!=INT_MAX)
        return dp[row][col];
        return dp[row][col]=tri[row][col]+min(func(row+1,col,tri),func(row+1,col+1,tri));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<triangle.size();i++)
        {
            dp.push_back({});
            for(int j=0;j<triangle[i].size();j++)
            dp[i].push_back(INT_MAX);
        }
        return func(0,0,triangle);
    }
};
