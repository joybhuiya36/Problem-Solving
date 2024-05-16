class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x) return -1;
        mp[0]=-1;
        int res=sum-x;
        int find,ans=INT_MIN;
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>=res)
            {
                find=sum-res;
                if(mp.count(find))
                {
                    ans=max(ans,i-mp[find]);
                }
            }
        }
        return ans==INT_MIN? -1:n-ans;
    }
};
