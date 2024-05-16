class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total=0, count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else if(nums[i]!=0 && count>0)
            {
                total+=(count*(count+1))/2;
                count=0;
            }
        }
        if(count>0)
        total+=(count*(count+1))/2;
        return total;
    }
};
