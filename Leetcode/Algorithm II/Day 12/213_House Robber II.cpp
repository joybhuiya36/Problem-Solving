class Solution {
public:
int n;
vector<int> dp;
vector<int> dp2;
int dp2_func(int idx, vector<int> &nums)
    {
        if(idx>=n)
        return 0;
        if(dp2[idx]!=-1)
        return dp2[idx];
        return dp2[idx]=nums[idx]+max(dp2_func(idx+2,nums),dp2_func(idx+3,nums));
    }
    int dp_func(int idx, vector<int> &nums)
    {
        if(idx>=n-1)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        return dp[idx]=nums[idx]+max(dp_func(idx+2,nums),dp_func(idx+3,nums));
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1) return nums[0];
        dp.resize(n,-1);
        dp2.resize(n,-1);
        return max(dp_func(0,nums),max(dp2_func(1,nums),dp2_func(2,nums)));
    }
};
