class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size(), mn=nums[0],mx=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<mn)
            mn=nums[i];
            else if(nums[i]>mx)
            mx=nums[i];
        }
        while(mx%mn!=0)
        {
            n=mn;
            mn=mx%mn;
            mx=n;
        }
        return mn;
    }
};
