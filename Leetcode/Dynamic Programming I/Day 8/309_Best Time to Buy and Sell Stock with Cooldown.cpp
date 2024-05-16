//DP
//Memorization
class Solution {
public:
    int stockSell(int i, bool take, vector<int> &p, vector<vector<int>> &dp, int &n)
    {
        if(i>=n)
        return 0;
        if(dp[i][take]!=-1)
        return dp[i][take];
        if(take==false)
        return dp[i][take]=max(-p[i]+stockSell(i+1,true,p,dp,n),stockSell(i+1,false,p,dp,n));
        else return dp[i][take]=max(p[i]+stockSell(i+2,false,p,dp,n),stockSell(i+1,true,p,dp,n));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return stockSell(0,false,prices,dp,n);
    }
};
//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n-1][1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            for(int take=0;take<2;take++)
            {
                if(take==0)
                dp[i][take]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                else dp[i][take]=max(prices[i]+dp[i+2][0],dp[i+1][1]);
            }
        }
        return dp[0][0];
    }
};
//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<int> cur(2,0);
        vector<int> next(2,0);
        vector<int> next2(2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int take=0;take<2;take++)
            {
                if(take==0)
                cur[take]=max(-prices[i]+next[1],next[0]);
                else cur[take]=max(prices[i]+next2[0],next[1]);
            }
            next2=next;
            next=cur;
        }
        return cur[0];
    }
};
//Greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int old_buy=-prices[0], old_sell=0, old_cool=0;
       int cur_buy=0, cur_sell=0, cur_cool=0;
        for(int i=1;i<n;i++)
        {
            cur_buy=max(old_buy,old_cool-prices[i]);
            cur_sell=max(old_sell,old_buy+prices[i]);
            cur_cool=max(old_cool,old_sell);
            old_buy=cur_buy;
            old_sell=cur_sell;
            old_cool=cur_cool;
        }
        return cur_sell;
    }
};
//or same as previous
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int old_buy=-prices[0], sell=0, cool=0;
       int cur_buy=0;
        for(int i=1;i<n;i++)
        {
            cur_buy=max(old_buy,cool-prices[i]);
            cool=max(cool,sell);
            sell=max(sell,old_buy+prices[i]);
            old_buy=cur_buy;
        }
        return sell;
    }
};
