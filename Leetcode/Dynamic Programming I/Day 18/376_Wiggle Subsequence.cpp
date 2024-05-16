//Total 5 Approaches
//DP
//Memorization
class Solution {
public:
    int wig(int i, int consider, vector<int> &nums, vector<vector<int>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i][consider]!=-1)
        return dp[i][consider];
        for(int j=i+1;j<n;j++)
        {
            if(consider==1 && nums[i]>nums[j])
            dp[i][consider]=max(dp[i][consider],wig(j,!consider,nums,dp,n));

            else if(consider==0 && nums[i]<nums[j])
            dp[i][consider]=max(dp[i][consider],wig(j,!consider,nums,dp,n));
        }
        return dp[i][consider]+=1;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans=0;
        for(int i=0;i<2;i++)
        {
            ans=max(ans,wig(0,i,nums,dp,n));
        }
        return ans+1;
    }
};
//Tabulation
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[n-1][0]=dp[n-1][1]=1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                dp[i][0]=max(dp[i][0],dp[j][1]);
                if(nums[i]>nums[j])
                dp[i][1]=max(dp[i][1],dp[j][0]);
            }
            dp[i][0]+=1;
            dp[i][1]+=1;
        }
        return max(dp[0][0],dp[0][1]);
    }
};
//Linear DP
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=dp[0][1]=1;    //0 means down, 1 means up
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=1+dp[i-1][0];
            }
            else if(nums[i-1]>nums[i])
            {
                dp[i][1]=dp[i-1][1];
                dp[i][0]=1+dp[i][1];
            }
            else
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
//Linear DP Space Optimized
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int up=1, down=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            up=down+1;
            else if(nums[i-1]>nums[i])
            down=up+1;
        }
        return max(up,down);
    }
};
//Greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int prediff=nums[1]-nums[0], diff;
        int count= prediff!=0? 2:1;
        for(int i=2;i<n;i++)
        {
            diff=nums[i]-nums[i-1];
            if((diff>0 && prediff<=0) || (diff<0 && prediff>=0))
            {
                count++;
                prediff=diff;
            }
        }
        return count;
    }
};
