class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int cur_max=nums[0], total_max=nums[0], sum=nums[0], cur_min=nums[0], total_min=nums[0];
        for(int i=1;i<n;i++)
        {
            cur_max=max(nums[i],cur_max+nums[i]);
            total_max=max(cur_max,total_max);
            cur_min=min(nums[i],cur_min+nums[i]);
            total_min=min(cur_min,total_min);
            sum+=nums[i];
        }
        return sum==total_min? total_max : max(total_max,sum-total_min);
    }
};
