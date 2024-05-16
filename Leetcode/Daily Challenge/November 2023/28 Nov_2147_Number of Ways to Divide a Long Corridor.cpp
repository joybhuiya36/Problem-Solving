class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')
            v.push_back(i);
        }
        n=v.size();
        if(n==0 || n%2==1) return 0;
        int mod=1e9+7;
        long long ans=1;
        for(int i=2;i<n;i+=2)
        {
            ans=(ans*(v[i]-v[i-1]))%mod;
        }
        return ans;
    }
};
