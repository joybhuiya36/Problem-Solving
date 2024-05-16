//DP
//Memorization
class Solution {
public:
    int LCS(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp, int &n1, int &n2)
    {
        if(i==n1 || j==n2)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(nums1[i]==nums2[j])
        return dp[i][j]=1+LCS(i+1,j+1,nums1,nums2,dp,n1,n2);
        else return dp[i][j]=max(LCS(i+1,j,nums1,nums2,dp,n1,n2),LCS(i,j+1,nums1,nums2,dp,n1,n2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return LCS(0,0,nums1,nums2,dp,n1,n2);
    }
};
//Tabulation
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
//or
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
//Space Optimization
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> cur(n2+1,0);
        vector<int> next(n2+1,0);
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                cur[j]=1+next[j+1];
                else cur[j]=max(next[j],cur[j+1]);
            }
            next=cur;
        }
        return cur[0];
    }
};
//or
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int cur[n2+1];
        int next[n2+1];
        cur[n2]=0;
        memset(next,0,sizeof(next));
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                cur[j]=1+next[j+1];
                else cur[j]=max(next[j],cur[j+1]);
            }
            for(int k=0;k<=n2;k++)
            next[k]=cur[k];
        }
        return cur[0];
    }
};
