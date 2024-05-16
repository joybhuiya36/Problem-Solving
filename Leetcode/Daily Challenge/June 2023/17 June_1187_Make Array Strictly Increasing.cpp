class Solution {
public:
map<pair<int,int>,int> mp;
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int pre, int &n, int &m)
    {
        if(idx==n) return 0;
        if(mp.count({idx,pre}))
        return mp[{idx,pre}];
        int op1=2001,op2=2001;
        if(arr1[idx]>pre)
        op1=solve(idx+1,arr1,arr2,arr1[idx],n,m);
        int j=(upper_bound(arr2.begin(),arr2.end(),pre)-arr2.begin());
        if(j!=m)
        op2=1+solve(idx+1,arr1,arr2,arr2[j],n,m);
        return mp[{idx,pre}]=min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int n=arr1.size(), m=arr2.size();
        int ans=solve(0,arr1,arr2,-1,n,m);
        return ans==2001? -1:ans;
    }
};
