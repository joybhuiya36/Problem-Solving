class Solution {
public:
typedef long long ll;
    ll find(vector<int> &nums, vector<int> &cost, int val)
    {
        ll rslt=0;
        for(int i=0;i<nums.size();i++)
        {
            rslt+=(ll)abs(nums[i]-val)*cost[i];
        }
        return rslt;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans=INT_MAX,cost1,cost2;
        int l,r,mid;
        auto minmax=minmax_element(nums.begin(),nums.end());
        l=*minmax.first; r=*minmax.second;
        if(l==r) return 0;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            cost1=find(nums,cost,mid);
            cost2=find(nums,cost,mid+1);
            ans=min(cost1,cost2);
            if(cost1>cost2)
            l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
