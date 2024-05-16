class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),diff,ans=0;
        int dp[n][1001];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                diff=nums[i]-nums[j]+500;
                if(dp[j][diff]>0)
                dp[i][diff]=dp[j][diff]+1;
                else dp[i][diff]=2;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
