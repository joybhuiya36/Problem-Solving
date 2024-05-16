class Solution {
public:
int n;
	int solve(int a, int b, string &s, string &rs, vector<vector<int>> &dp)
    {
        if(a==n || b==n) return 0;
        if(dp[a][b]!=-1)
        return dp[a][b];
        if(s[a]==rs[b])
        return dp[a][b]=1+solve(a+1,b+1,s,rs,dp);
        else return dp[a][b]=max(solve(a,b+1,s,rs,dp),solve(a+1,b,s,rs,dp));
        
    }
    int minInsertions(string s) {
        n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string rs=s;
        reverse(rs.begin(),rs.end());
        return n-solve(0,0,s,rs,dp);
    }
};
