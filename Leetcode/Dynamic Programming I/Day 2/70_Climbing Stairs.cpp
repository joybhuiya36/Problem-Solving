//Tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> dp(n+1);
        dp[1]=1; dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//Space Optimization
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int a=1, b=2, temp;
        for(int i=3;i<=n;i++)
        {
            temp=b;
            b=a+b;
            a=temp;
        }
        return b;
    }
};
//Memorization (2 Approach)
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
class Solution {
public:
vector<int> dp;
    int dp_func(int n)
    {
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=dp_func(n-1)+dp_func(n-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return dp_func(n);
    }
};
