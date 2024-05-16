//Greedy Approach
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
//DP Approach (Memorization)
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
            // cout<<"idx->"<<idx<<" jump->"<<i<<" reach->"<<idx+nums[idx]<<endl;
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
