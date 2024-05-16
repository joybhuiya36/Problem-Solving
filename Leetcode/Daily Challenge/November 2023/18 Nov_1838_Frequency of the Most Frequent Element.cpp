//Sliding Windows
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,ans=0;
        int target,m;
        long long sum=0;
        sort(nums.begin(),nums.end());
        while(r<n)
        {
            target=nums[r];
            sum+=target;
            m=r-l+1;
            if((long long)target*m-sum>k)
            {
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
