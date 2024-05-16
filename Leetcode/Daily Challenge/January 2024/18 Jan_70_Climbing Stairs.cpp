class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int dp[n+1];
        dp[1]=1; dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//or
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
//or
class Solution {
public:
    int dp_func(int n)
    {
        if(dp[n]!=-1)
        return dp[n];
        if(n<=2)
        return n;
        return dp[n]=dp_func(n-1)+dp_func(n-2);
    }
    vector<int> dp;
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return dp_func(n);
    }
};
