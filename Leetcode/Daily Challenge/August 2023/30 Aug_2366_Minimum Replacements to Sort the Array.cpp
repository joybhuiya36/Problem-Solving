class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size(), m, p=nums[n-1];
        long long ans=0;
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]>p)
            {
                m=nums[i-1]/p;
                if(nums[i-1]%p==0)
                ans+=(m-1);
                else
                {
                    ans+=m;
                    p=nums[i-1]/((nums[i-1]/p)+1);
                }
            }
            else p=nums[i-1];
        }
        return ans;
    }
};
