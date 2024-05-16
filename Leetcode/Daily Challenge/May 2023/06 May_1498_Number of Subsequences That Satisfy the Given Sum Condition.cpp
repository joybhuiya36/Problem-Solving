class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        const int mod=1e9+7;
        vector<int> pow(n,1);
        for(int i=1;i<n;i++)
        pow[i]=(2*pow[i-1])%mod;
        int l=0, r=n-1,ans=0;
        sort(nums.begin(),nums.end());
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                ans=(ans+pow[r-l])%mod;
                l++;
            }
            else r--;
        }
        return ans;
    }
};
