class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool flag=false, cmp, inc;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            continue;
            cmp=nums[i-1]>nums[i];
            if(!flag)
            {
                flag=true;
                inc=cmp;
            }
            if(inc!=cmp)
            return false;
        }
        return true;
    }
};
