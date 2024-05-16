class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        int dp[10001]={0};
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[nums[i]]+=nums[i];
            mx=max(mx,nums[i]);
        }
        for(int i=2;i<=mx;i++)
        {
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        return dp[mx];
    }
};
