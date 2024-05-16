//DP Memorization
class Solution {
public:
    int LIS(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(idx==nums.size()-1)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int count=0;
        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[idx]<nums[i])
            count=max(count,1+LIS(i,nums,dp));
        }
        return dp[idx]=count;
    }
    int lengthOfLIS(vector<int>& nums) {
        int mx=0;
        vector<int> dp(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        mx=max(mx,LIS(i,nums,dp));
        return 1+mx;
    }
};
//DP Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int ans=0;
        for(int i = 0;i<nums.size();i++){
            for(int j= 0;j<i;j++){
                dp[i] = max(dp[i],nums[j]<nums[i]?dp[j]+1:0);
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
