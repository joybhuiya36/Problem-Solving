//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,0);
        dp[n-2]=nums[n-2];
        for(int i=n-3;i>=0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        for(int i=1;i<n+1;i++)
        dp[i]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return max(dp[0],dp[1]);
    }
};
//Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans1;
        if(nums.size()==1) return nums[0];
        int pre1=nums[nums.size()-2], pre2=0, cur=0;
        int non_rob, rob;
        for(int i=nums.size()-3;i>=0;i--)
        {
            non_rob=pre1;
            rob=nums[i]+pre2;
            cur=max(rob,non_rob);
            pre2=pre1;
            pre1=cur;
        }
        ans1=max(cur,pre1);
        pre1=nums[nums.size()-1]; pre2=0; cur=0;
        for(int i=nums.size()-2;i>0;i--)
        {
            non_rob=pre1;
            rob=nums[i]+pre2;
            cur=max(rob,non_rob);
            pre2=pre1;
            pre1=cur;
        }
        return max(ans1,max(cur,pre1));
    }
};
//Memorization
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
