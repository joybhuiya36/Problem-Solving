class Solution {
public:
int dp[21][21];
	int check(int l, int r, vector<int> &nums)
    {
        if(l>r) return 0;
        if(l==r) return nums[l];
        if(dp[l][r]!=-1)
        return dp[l][r];
        return dp[l][r]=max(nums[l]-check(l+1,r,nums),nums[r]-check(l,r-1,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size(), fst;
        memset(dp,-1,sizeof(dp));
        fst=check(0,n-1,nums);
        return fst>=0? true:false;
    }
};
