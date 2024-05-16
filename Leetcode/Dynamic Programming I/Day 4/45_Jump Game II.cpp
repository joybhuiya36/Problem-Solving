//Gready
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
//DP (Tabulation+Memorization)
//Tabulation
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),k;
        vector<int> dp(n,1e5);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            k=min(i+nums[i],n-1);
            for(int j=i+1;j<=k;j++)
            {
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
        return dp[0];
    }
};
//Memorization
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
