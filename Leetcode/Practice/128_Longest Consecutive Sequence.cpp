class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        sort(nums.begin(),nums.end());
        int count=1,ans=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            continue;
            if(nums[i-1]+1==nums[i])
            count++;
            else count=1;
            ans=max(ans,count);
        }
        return ans;
    }
};
