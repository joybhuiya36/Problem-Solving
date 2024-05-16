//Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1) return false;
        int mx=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i+nums[i]>mx)
            mx=i+nums[i];
            if(mx>=nums.size()-1)
            return true;
            else if(i==mx)
            return false;
        }
        return true;
    }
};
//DP (Tabulation+Memorization)
//Tabulation
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==0)
            continue;
            for(int j=i+1;j<=i+nums[i];j++) //how much reachable from this idx
            {
                if(j<n && dp[j]==true)      //reachable idx should be less than n to eliminate overflows
                {
                    dp[i]=true;
                    break;
                }
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
        return true;
        if(dp[idx]!=-1)
        return dp[idx];
        if(nums[idx]==0)
        return false;
        bool check=false;
        for(int i=nums[idx];i>=1;i--)
        {
            check=jump(idx+i,nums,dp);
            if(check==true)
            break;
        }
        return dp[idx]=check;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return jump(0,nums,dp);
    }
};
