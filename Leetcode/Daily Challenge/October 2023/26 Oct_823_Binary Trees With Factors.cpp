class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size(), mod=1e9+7;
        sort(arr.begin(),arr.end());
        unordered_map<int, long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && mp.count(arr[i]/arr[j]))
                {
                    mp[arr[i]]+=(mp[arr[j]]*mp[arr[i]/arr[j]]);
                }
            }
        }
        int rslt=0;
        for(auto &it:mp)
        rslt=(it.second+rslt)%mod;
        return rslt;
    }
};
