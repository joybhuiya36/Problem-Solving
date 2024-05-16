//DP
//Memorization
class Solution {
public:
int mod=1e9+7;
    int dfs(int i, int &z, int &o, vector<int> &dp)
    {
        if(i==0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=dfs(i-z,z,o,dp)%mod+dfs(i-o,z,o,dp)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long ans=0;
        vector<int> dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            ans+=dfs(i,zero,one,dp);
            ans%=mod;
        }
        return ans;
    }
};
//Tabulation
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod=1e9+7;
        long long ans=0;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0)
            dp[i]+=dp[i-zero]%mod;
            if(i-one>=0)
            dp[i]+=dp[i-one]%mod;
        }
        for(int i=low;i<=high;i++)
        {
            ans+=dp[i];
            ans%=mod;
        }
        return ans;
    }
};
