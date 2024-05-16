//DP
//Memorization
class Solution {
public:
    int solve(int i, int total, int &amt, vector<int> &coins, vector<vector<int>> &dp, int &n)
    {
        if(total==amt)
        return 1;
        if(total>amt)
        return 0;
        if(dp[i][total]!=-1)
        return dp[i][total];
        int count=0;
        for(int j=i;j<n;j++)
        {
            count+=solve(j,total+coins[j],amt,coins,dp,n);
        }
        return dp[i][total]=count;
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        return solve(0,0,amt,coins,dp,n);
    }
};
