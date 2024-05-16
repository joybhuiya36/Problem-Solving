class Solution {
public:
    int lcs(int i, int j, string &s1, string &s2, int &m, int &n, vector<vector<int>> &dp, int ps1[], int ps2[])
    {
        if(i==m)
        return ps2[n]-ps2[j];
        if(j==n)
        return ps1[m]-ps1[i];
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=lcs(i+1,j+1,s1,s2,m,n,dp,ps1,ps2);
        }
        else
        {
            return dp[i][j]=(min(s1[i]+lcs(i+1,j,s1,s2,m,n,dp,ps1,ps2),s2[j]+lcs(i,j+1,s1,s2,m,n,dp,ps1,ps2)));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int pre_s1[m+1], pre_s2[n+1];
        pre_s1[0]=pre_s2[0]=0;
        for(int i=0;i<m;i++)
        pre_s1[i+1]=pre_s1[i]+s1[i];
        for(int i=0;i<n;i++)
        pre_s2[i+1]=pre_s2[i]+s2[i];
        return lcs(0,0,s1,s2,m,n,dp,pre_s1,pre_s2);
    }
};
