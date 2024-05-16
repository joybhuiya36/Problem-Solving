class Solution {
public:
int n,mod=1e9+7;
	int solve(int i, string &s, int &k, vector<int> &dp)
    {
        if(i==n)
        return 1;
        if(s[i]=='0')
        return dp[i]=0;
        if(dp[i]!=-1)
        return dp[i];
        long num=0; int count=0;
        for(int j=i;j<n;j++)
        {
            num=(num*10)+(s[j]-'0');
            if(num>k) break;
            count=(count+solve(j+1,s,k,dp))%mod;
        }
        return dp[i]=count;
    }
    int numberOfArrays(string s, int k) {
        n=s.length();
        vector<int> dp(n,-1);
        return solve(0,s,k,dp);
    }
};
