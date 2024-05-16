class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1, r=1, count=1, n=nums.size();
        while(r<n)
        {
            if(nums[r]==nums[r-1])
            count++;
            else count=1;
            if(count<=2)
            nums[l++]=nums[r];
            r++;
        }
        return l;
    }
};
