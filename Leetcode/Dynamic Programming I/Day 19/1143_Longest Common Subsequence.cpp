//DP
//Memorization
class Solution {
public:
    int LCS(int i, int j, string &txt1, string &txt2, vector<vector<int>> &dp)
    {
        if(i==txt1.length() || j==txt2.length())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int count=0;
        if(txt1[i]==txt2[j])
        count+=1+LCS(i+1,j+1,txt1,txt2,dp);
        else count+=max(LCS(i+1,j,txt1,txt2,dp),LCS(i,j+1,txt1,txt2,dp));
        return dp[i][j]=count;
    }
    int longestCommonSubsequence(string txt1, string txt2) {
        vector<vector<int>> dp(txt1.length(),vector<int>(txt2.length(),-1));
        return LCS(0,0,txt1,txt2,dp);
    }
};
//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string txt1, string txt2) {
        int m=txt1.length(), n=txt2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(txt1[i]==txt2[j])
                dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
//Space Optimization
class Solution {
public:
    int longestCommonSubsequence(string txt1, string txt2) {
        int m=txt1.length(), n=txt2.length();
        int pre[n+1], cur[n+1];
        memset(pre,0,sizeof(pre));
        cur[n]=0;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(txt1[i]==txt2[j])
                cur[j]=1+pre[j+1];
                else cur[j]=max(pre[j],cur[j+1]);
            }
            for(int k=0;k<n+1;k++)
            pre[k]=cur[k];
        }
        return cur[0];
    }
};
