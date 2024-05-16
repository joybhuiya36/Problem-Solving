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
