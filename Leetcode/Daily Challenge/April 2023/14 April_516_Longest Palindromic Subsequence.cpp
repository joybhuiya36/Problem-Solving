//Without reverse string copied
class Solution {
public:
	int lps(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(i>j)
        return 0;
        else if(i==j)
        return 1;
        if(s[i]==s[j])
        return dp[i][j]=2+lps(i+1,j-1,s,dp);
        else
        return dp[i][j]=max(lps(i+1,j,s,dp),lps(i,j-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,(vector<int>(n,-1)));
        return lps(0,n-1,s,dp);
    }
};
//Pass through string index(optimal)
class Solution {
public:
int n;
    int LCS(string &s, string &rs, int i, int j, vector<vector<int>> &dp)
    {
        if(i==n || j==n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==rs[j])
        return dp[i][j]=1+LCS(s,rs,i+1,j+1,dp);
        else
        {
            int op1=LCS(s,rs,i,j+1,dp);
            int op2=LCS(s,rs,i+1,j,dp);
            return dp[i][j]=max(op1,op2);
        }
    }
    int longestPalindromeSubseq(string s) {
        n=s.length();
        if(n==1) return 1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        string rs;
        for( int i=n-1; i>=0; i--)
        rs+=s[i];
        return LCS(s,rs,0,0,dp);
    }
};
//Direct passing string
class Solution {
public:
vector<vector<int>> dp;
    int LCS(string s, string rs)
    {
        if(s.length()==0 || rs.length()==0)
        return 0;
        if(dp[s.length()][rs.length()]!=-1)
        return dp[s.length()][rs.length()];
        if(s[0]==rs[0])
        return dp[s.length()][rs.length()]=1+LCS(s.substr(1),rs.substr(1));
        else
        {
            int op1=LCS(s.substr(0),rs.substr(1));
            int op2=LCS(s.substr(1),rs.substr(0));
            return dp[s.length()][rs.length()]=max(op1,op2);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        if(n==1) return 1;
        dp.resize(n+1,vector<int>(n+1,-1));
        string rs;
        for( int i=n-1; i>=0; i--)
        rs+=s[i];
        return LCS(s,rs);
    }
};
