class Solution {
public:
int n;
vector<int> dp;
    int dp_func(int idx, vector<int> &nums)
    {
        if(idx>=n)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        return dp[idx]=nums[idx]+max(dp_func(idx+2,nums),dp_func(idx+3,nums));
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return max(dp_func(0,nums),dp_func(1,nums));
    }
};
