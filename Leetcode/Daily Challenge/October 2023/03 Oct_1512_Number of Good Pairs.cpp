class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int a[101]={0};
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[nums[i]];
            a[nums[i]]++;
        }
        return ans;
    }
};
