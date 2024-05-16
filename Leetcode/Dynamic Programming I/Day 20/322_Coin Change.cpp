//DP
//Memorization
class Solution {
public:
    int solve(int i, long long total, vector<int> &coins, vector<vector<int>> &dp, int &amt, int &n)
    {
        if(i==n)
        return total==amt? 0:1e9;
        if(total==amt)
        return 0;
        if(total>amt)
        return 1e9;
        if(dp[i][total]!=-1)
        return dp[i][total];
        int taken=1+solve(i,total+coins[i],coins,dp,amt,n);
        int not_taken=solve(i+1,total,coins,dp,amt,n);
        return dp[i][total]=min(taken,not_taken);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        int ans=solve(0,0,coins,dp,amt,n);
        return ans==1e9? -1:ans;
    }
};
//Tabultion
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size(), target=amt;
        vector<vector<int>> dp(n+1,vector<int>(amt+1));
        int taken, not_taken;
        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        for(int i=0;i<=amt;i++)
        dp[0][i]=1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(j>=coins[i-1])
                taken=1+dp[i][j-coins[i-1]];
                else taken=1e9;
                not_taken=dp[i-1][j];
                dp[i][j]=min(taken,not_taken);
            }
        }
        return dp[n][amt]==1e9? -1:dp[n][amt];
    }
};
//Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<int> pre(amt+1,1e9), cur(amt+1);
        int taken, not_taken;
        for(int i=1;i<=n;i++)
        {
            cur[0]=pre[0]=0;
            for(int j=1;j<=amt;j++)
            {
                if(j>=coins[i-1])
                taken=1+cur[j-coins[i-1]];
                else taken=1e9;
                not_taken=pre[j];
                cur[j]=min(taken,not_taken);
            }
            pre=cur;
        }
        return pre[amt]==1e9? -1:pre[amt];
    }
};
