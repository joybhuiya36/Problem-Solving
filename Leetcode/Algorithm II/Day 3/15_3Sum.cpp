class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size(), ptr, left, right;
        sort(nums.begin(),nums.end());
        if(nums[0]>0) return ans;
        for(int ptr=0;ptr<n-2;ptr++)
        {
            if(ptr-1>=0 && nums[ptr]==nums[ptr-1])
            continue;
            left=ptr+1; right=n-1;
            while(left<right)
            {
                if(nums[ptr]+nums[left]+nums[right]>0)
                right--;
                else if(nums[ptr]+nums[left]+nums[right]<0)
                left++;
                else
                {
                    ans.push_back({nums[ptr],nums[left],nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                    left++;
                    right--;
                    while(left<right && nums[right]==nums[right+1])
                    right--;
                }
            }
        }
        return ans;
    }
};
