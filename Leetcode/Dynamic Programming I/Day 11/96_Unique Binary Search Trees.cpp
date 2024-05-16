//DP
//Tabulation
class Solution {
public:
    int numTrees(int n) {
        int sum;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                sum=1;
                if(j-1>0)
                sum=dp[j-1];
                if(i-j>0)
                sum*=dp[i-j];
                dp[i]+=sum;
            }
        }
        return dp[n];
    }
};
//Memorization
class Solution {
public:
    int func(int i, int *dp)
    {
        if(i==1)
        return 1;
        if(dp[i]!=0)
        return dp[i];
        for(int j=1;j<=i;j++)
        {
            int sum=1;
            if(j-1>0)
            sum=func(j-1,dp);
            if(i-j>0)
            sum*=func(i-j,dp);
            dp[i]+=sum;
        }
        return dp[i];
    }
    int numTrees(int n) {
        int sum;
        int dp[n+1];
        memset(dp,-0,sizeof(dp));
        return func(n,dp);
    }
};
