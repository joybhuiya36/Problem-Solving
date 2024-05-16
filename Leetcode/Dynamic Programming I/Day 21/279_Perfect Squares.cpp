//DP
//Memorization
class Solution {
public:
    int perfect(int start, int n, int &limit, vector<int> &dp)
    {
        if(n==0)
        return 0;
        if(n<0)
        return 1e9;
        if(dp[n]!=-1)
        return dp[n];
        int mn=1e9;
        for(int i=start;i<=limit;i++)
        {
            mn=min(mn,1+perfect(i,n-(i*i),limit,dp));;
        }
        return dp[n]=mn;
    }
    int numSquares(int n) {
        if(n&(n-1)==0) return 1;
        int limit=sqrt(n);
        vector<int> dp(n+1,-1);
        return perfect(1,n,limit,dp);
    }
};
