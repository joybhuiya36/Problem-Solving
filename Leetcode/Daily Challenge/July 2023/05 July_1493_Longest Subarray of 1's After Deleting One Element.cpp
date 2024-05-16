class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),sum=0,ans=0,pre=0,dlt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            sum+=1;
            else
            {
                ans=max(ans,sum+pre);
                pre=sum;
                sum=0;
                dlt=1;
            }
        }
        if(nums.back()==1)
        ans=max(ans,sum+pre);
        if(dlt==0)
        ans--;
        return ans;
    }
};
