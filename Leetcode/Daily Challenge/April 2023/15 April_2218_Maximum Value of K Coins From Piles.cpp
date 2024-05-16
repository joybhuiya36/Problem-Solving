class Solution {
public:
int n;
    int func(int i, vector<vector<int>> &pl, int k, vector<vector<int>> &dp)
    {
        if(i==n)
        return 0;
        if(dp[i][k]!=-1)
        return dp[i][k];
        int mx= func(i+1,pl,k,dp);

        for(int j=0;j<pl[i].size();j++)
        {
            if(j+1<=k)
            {
                mx=max(mx,func(i+1,pl,k-j-1,dp)+pl[i][j]);
            }
            else break;
        }
        return dp[i][k]=mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<piles[i].size();j++)
            piles[i][j]+=piles[i][j-1];
        }
        return func(0,piles,k,dp);
    }
};
