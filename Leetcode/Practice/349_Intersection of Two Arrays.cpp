class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        unordered_set<int> mp,ans;
        for(int i=0;i<m;i++)
        mp.insert(nums1[i]);
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums2[i]))
            ans.insert(nums2[i]);
        }
        for(auto &it:ans)
        v.push_back(it);
        return v;
    }
};
