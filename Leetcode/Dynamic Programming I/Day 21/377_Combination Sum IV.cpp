//DP
//Mmeorization
class Solution {
public:
    int combi(vector<int> &nums, int t, vector<int> &dp, int &n)
    {
        if(t==0)
        return 1;
        if(t<0)
        return 0;
        if(dp[t]!=-1)
        return dp[t];
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=combi(nums,t-nums[i],dp,n);
        }
        return dp[t]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return combi(nums,target,dp,n);
    }
};
