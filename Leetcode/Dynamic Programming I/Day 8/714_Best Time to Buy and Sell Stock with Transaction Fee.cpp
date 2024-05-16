//DP
//Memorization
class Solution {
public:
    int profit(int i, int buy, int &fee, vector<int> &p, vector<vector<int>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i][buy]!=-1)
        return dp[i][buy];
        if(buy==0)
        return dp[i][buy]=max(-p[i]-fee+profit(i+1,!buy,fee,p,dp,n),profit(i+1,buy,fee,p,dp,n));
        else return dp[i][buy]=max(p[i]+profit(i+1,!buy,fee,p,dp,n),profit(i+1,buy,fee,p,dp,n));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profit(0,0,fee,prices,dp,n);
    }
};
//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0]=max(-prices[i]-fee+dp[i+1][1],dp[i+1][0]);
            dp[i][1]=max(prices[i]+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][0];
    }
};
//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int cur0,cur1,next0=0,next1=0;
        for(int i=n-1;i>=0;i--)
        {
            cur0=max(-prices[i]-fee+next1,next0);
            cur1=max(prices[i]+next0,next1);
            next0=cur0; next1=cur1;
        }
        return cur0;
    }
};
