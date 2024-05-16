class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        int i=0,flag=0;
        for(;i<nums.size()-1;i++)
        {
            flag=0;
            if(nums[i]==nums[i+1])
            {
                flag=1;
                continue;
            }
            else break;
        }
        if(flag==1) return true;
        if(nums[i]>nums[i+1])
        {
            while(i<nums.size()-1)
            {
                if(nums[i]<nums[i+1])
                return false;
                i++;
            }
        }
        else if(nums[i]<nums[i+1])
        {
            while(i<nums.size()-1)
            {
                if(nums[i]>nums[i+1])
                return false;
                i++;
            }
        }
        return true;
    }
};
