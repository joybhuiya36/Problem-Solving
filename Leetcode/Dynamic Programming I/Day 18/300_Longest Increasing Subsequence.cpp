//3 Approaches
//DP
//Memorization
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
//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=1;
        vector<int> dp(n,1);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
//Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), idx;
        vector<int> v={nums[0]};
        for(int i=1;i<n;i++)
        {
            idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            if(idx==v.size())
            v.push_back(nums[i]);
            else v[idx]=nums[i];
        }
        return v.size();
    }
};
