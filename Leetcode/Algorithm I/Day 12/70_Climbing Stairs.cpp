//To-Down Approach
class Solution {
public:
	vector<int> dp;
    int dp_func(int n)
    {
        if(dp[n]!=-1)
        return dp[n];
        if(n<=2)
        return n;
        return dp[n]=dp_func(n-1)+dp_func(n-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return dp_func(n);
    }
};
//Bottom-Up Approach
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};
