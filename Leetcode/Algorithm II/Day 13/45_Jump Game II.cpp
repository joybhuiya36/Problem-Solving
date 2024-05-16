//Greedy Approach
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0, far=0, curEnd=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(far<i+nums[i])
            far=i+nums[i];
            if(curEnd==i)
            {
                curEnd=far;
                jump++;
            }
        }
        return jump;
    }
};
//DP Approach
class Solution {
public:
    int jump(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(idx>=nums.size()-1)
        {
            return 0;
        }
        if(dp[idx]!=-1)
        return dp[idx];
        if(nums[idx]==0)
        return 1e6;
        int mn=1e6;
        for(int i=nums[idx];i>=1;i--)
        {
            mn=min(mn,1+jump(idx+i,nums,dp));
        }
        return dp[idx]=mn;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return jump(0,nums,dp);
    }
};
