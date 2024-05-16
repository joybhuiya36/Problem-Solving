//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+3,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            dp[i]=nums[i]+max(dp[i+2],dp[i+3]);
        }
        return max(dp[0],dp[1]);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        nums.push_back(0);
        for(int i=n-2;i>=0;i--)
        {
            nums[i]=max(nums[i]+nums[i+2],nums[i+1]);
        }
        return max(nums[0],nums[1]);
    }
};
//Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre1=nums.back(), pre2=0, cur=0;
        int rob, non_rob;
        for(int i=nums.size()-2;i>=0;i--)
        {
            non_rob=pre1;
            rob=nums[i]+pre2;
            cur=max(rob,non_rob);
            pre2=pre1;
            pre1=cur;
        }
        return max(cur,pre1);
    }
};
//Memorization
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
