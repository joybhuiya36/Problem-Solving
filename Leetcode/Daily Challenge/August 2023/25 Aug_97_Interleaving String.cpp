class Solution {
public:
int m,n,o;
int dp[101][101];
	bool check(int i, int j, string &s1, string &s2, string &s3)
    {
        if(i==m && j==n && i+j==o)
        return true;
        if(i+j>=o) return false;
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool rslt=false;
        if(s1[i]==s3[i+j])
        rslt=check(i+1,j,s1,s2,s3);
        if(rslt) return dp[i][j]=true;
        if(s2[j]==s3[i+j])
        rslt=check(i,j+1,s1,s2,s3);
        return dp[i][j]=rslt;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m=s1.length(); n=s2.length(); o=s3.length();
        if(m+n!=o) return false;
        if(m==0) return s2==s3;
        if(n==0) return s1==s3;
        memset(dp,-1,sizeof(dp));
        return check(0,0,s1,s2,s3);
    }
};
