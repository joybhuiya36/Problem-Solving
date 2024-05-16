//Two Pointer_One-Pass Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,ptr=0,right=nums.size()-1;
        while(ptr<=right)
        {
            if(nums[ptr]==0)
            swap(nums[left++],nums[ptr++]);
            else if(nums[ptr]==2)
            swap(nums[ptr],nums[right--]);
            else
            ptr++;
        }
    }
};
//Two_pass way by counting in a hash
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> mp(3,0);
        int color=0;
        for(int& i:nums)
        mp[i]++;
        for(int i=0;i<nums.size();color++)
        {
            while(mp[color]--)
            nums[i++]=color;
        }
    }
};
