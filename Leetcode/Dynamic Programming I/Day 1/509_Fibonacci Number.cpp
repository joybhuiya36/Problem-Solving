//DP Tabulation
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);
        if(n==0) return 0;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
//Without DP
class Solution {
public:
        int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        for (int i = 1; i <= n - 1; i++) { 
            int sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }
};
