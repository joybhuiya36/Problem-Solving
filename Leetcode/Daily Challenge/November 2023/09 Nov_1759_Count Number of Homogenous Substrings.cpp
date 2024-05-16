class Solution {
public:
    int countHomogenous(string s) {
        int n=s.length();
        if(n==1) return 1;
        int  i=1, mod=1e9+7;
        long long c=1, ans=0;
        while(i<n)
        {
            while(i<n && s[i-1]==s[i])
            {
                c++; i++;
            }
            ans=(ans+((c*(c+1))/2))%mod;
            c=1; i++;
        }
        if(s[n-1]!=s[n-2])
        ans++;
        return ans;
    }
};
