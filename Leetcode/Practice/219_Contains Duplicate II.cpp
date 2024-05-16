class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size(),r=min(k,n-1);
        if(k==0) return false;
        unordered_set<int> mp;
        for(int i=0;i<=r;i++)
        {
            if(mp.count(nums[i]))
            return true;
            mp.insert(nums[i]);
        }
        int l=0; r=k+1;
        while(r<n)
        {
            auto it=mp.find(nums[l]);
            mp.erase(it);
            l++;
            if(mp.count(nums[r]))
            return true;
            mp.insert(nums[r]);
            r++;
        }
        return false;
    }
};
