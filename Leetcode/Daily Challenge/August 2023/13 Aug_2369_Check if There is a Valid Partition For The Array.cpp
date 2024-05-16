class Solution {
public:
int dp[100001];
    bool checker(int i,vector<int> &nums, int &n)
    {
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        bool rslt=false;
        if(i+1<n && nums[i]==nums[i+1])
        rslt|=checker(i+2,nums,n);
        if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
        rslt|=checker(i+3,nums,n);
        if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
        rslt|=checker(i+3,nums,n);
        return dp[i]=rslt;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return checker(0,nums,n);
    }
};
