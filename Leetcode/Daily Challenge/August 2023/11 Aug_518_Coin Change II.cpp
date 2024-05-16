//DP
//Memorization
class Solution {
public:
    int solve(int i, int total, int &amt, vector<int> &coins, vector<vector<int>> &dp, int &n)
    {
        if(total==amt)
        return 1;
        if(dp[i][total]!=-1)
        return dp[i][total];
        int count=0;
        for(int j=i;j<n;j++)
        {
            if(total+coins[j]>amt) break;
            count+=solve(j,total+coins[j],amt,coins,dp,n);
        }
        return dp[i][total]=count;
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        sort(coins.begin(),coins.end());
        return solve(0,0,amt,coins,dp,n);
    }
};
//or
class Solution {
public:
    int changeCoins(int i, int amt, vector<int> &c, vector<vector<int>> &dp)
    {
        if(amt==0) return 1;
        else if(amt<0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        if(i==0)
        {
            if(amt%c[i]==0) return 1;
            else return 0;
        }
        int not_taken=changeCoins(i-1,amt,c,dp);
        int taken=changeCoins(i,amt-c[i],c,dp);
        return dp[i][amt]=taken+not_taken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return changeCoins(n-1,amount,coins,dp);
    }
};
