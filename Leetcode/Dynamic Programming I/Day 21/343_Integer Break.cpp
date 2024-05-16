//DP
//Memorization
class Solution {
public:
    int intbrk(int start, int prd, vector<int> &dp, int n, int &len)
    {
        if(n==0)
        return prd;
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return prd*dp[n];
        int mx=1;
        for(int i=start;i<len;i++)
        {
            mx=max(mx,intbrk(i,prd*i,dp,n-i,len));
        }
        return dp[n]=mx;
    }
    int integerBreak(int n) {
        int len=n;
        vector<int> dp(n+1,-1);
        return intbrk(1,1,dp,n,len);
    }
};
