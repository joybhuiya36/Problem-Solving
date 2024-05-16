class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n,-1);
        if(k>=n) return v;
        vector<long long> pfx(n+1,0);
        for(int i=0;i<n;i++)
        pfx[i+1]=pfx[i]+nums[i];
        for(int i=0;i<n;i++)
        {
            if(i<k || i>=n-k)
            continue;
            else
            v[i]=(pfx[i+k+1]-pfx[i-k])/(2*k+1);
        }
        return v;
    }
};
