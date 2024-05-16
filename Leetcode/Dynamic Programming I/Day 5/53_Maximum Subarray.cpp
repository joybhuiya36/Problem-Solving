//Greedy (Kadane's Algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c_mx=nums[0], t_mx=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            c_mx=max(nums[i],c_mx+nums[i]);
            t_mx=max(c_mx,t_mx);
        }
        return t_mx;
    }
};
//Divide and Conquer
class Solution {
public:
    int cross_merge(int &l, int &mid, int &r, vector<int> &nums)
    {
        int left_max=INT_MIN;
        int right_max=INT_MIN;
        int sum=0;
        for(int i=mid;i>=l;i--)
        {
            sum+=nums[i];
            if(sum>left_max)
            left_max=sum;
        }
        sum=0;
        for(int i=mid+1;i<=r;i++)
        {
            sum+=nums[i];
            if(sum>right_max)
            right_max=sum;
        }
        return left_max+right_max;
    }
    int divide(int l, int r, vector<int> &nums)
    {
        if(l==r) return nums[l];
        int mid=(l+r)/2;
        int left_sub=divide(l,mid,nums);
        int right_sub=divide(mid+1,r,nums);
        int cross_sub=cross_merge(l,mid,r,nums);
        return max(cross_sub, max(left_sub,right_sub));
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return divide(0,n-1,nums);
    }
};
//or
class Solution {
public:
    vector<int> pre, suf;
    int maxSubArray(vector<int>& nums) {
        pre = suf = nums;
        for(int i = 1; i < size(nums); i++)  pre[i] += max(0, pre[i-1]);
        for(int i = size(nums)-2; ~i; i--)   suf[i] += max(0, suf[i+1]);
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L == R) return A[L];
        int mid = (L + R) / 2;
        return max({ maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1] });
    }	
};
//DP
//Memorization
class Solution {
public:
    int sub(int idx, bool takeit, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(idx==nums.size())
        return takeit==true? 0:-1e6;
        if(dp[idx][takeit]!=-1)
        return dp[idx][takeit];
        if(takeit==true)
        return dp[idx][takeit]=max(0,nums[idx]+sub(idx+1,true,nums,dp));
        int not_taken=sub(idx+1,false,nums,dp);
        int taken=nums[idx]+sub(idx+1,true,nums,dp);
        return dp[idx][takeit]=max(not_taken,taken);
    }
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return sub(0,false,nums,dp);
    }
};
//Tabulation
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for(int i = 1; i < size(nums); i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1]);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        }
        return dp[0].back();
    }
};
