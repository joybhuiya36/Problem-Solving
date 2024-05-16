//DP
//Memorization
class Solution {
public:
    int time(int i, bool take, vector<int> &p, vector<vector<int>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i][take]!=-1)
        return dp[i][take];
        if(take==false)
        return dp[i][take]=max(time(i+1,take,p,dp,n),(-1*p[i])+time(i+1,!take,p,dp,n));
        else return dp[i][take]=max(p[i],time(i+1,take,p,dp,n));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return time(0,false,prices,dp,n);
    }
};
//One Pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mx=0,mn=INT_MAX;
    for(int i=0;i<prices.size();i++)
    {
		if(prices[i]<mn)
		mn=prices[i];
		else if(prices[i]-mn>mx)
		mx=prices[i]-mn;
    }
    return mx;
    }
};
