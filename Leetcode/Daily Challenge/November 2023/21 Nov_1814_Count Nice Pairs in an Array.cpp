class Solution {
public:
	int rev(int n)
    {
        int m=0;
        while(n)
        {
            m=(m*10)+(n%10);
            n/=10;
        }
        return m;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size(), mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            nums[i]-=rev(nums[i]);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            {
                cnt++;
                ans+=cnt;
            }
            else
            {
            	cnt=0;
            }
        }
        return ans%mod;
    }
};
