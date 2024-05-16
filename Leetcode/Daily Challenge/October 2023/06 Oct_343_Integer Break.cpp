class Solution {
public:
int dp[59];
    int intbrk(int start, int prd, int n, int &len)
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
            mx=max(mx,intbrk(i,prd*i,n-i,len));
        }
        return dp[n]=mx;
    }
    int integerBreak(int n) {
        int len=n;
        memset(dp,-1,sizeof(dp));
        return intbrk(1,1,n,len);
    }
};
//or
class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0 || n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int maxi=0;
        
        for(int ind=1;ind<n;ind++){
            int temp=max(ind*(n-ind), ind * solve(n-ind,dp));
            maxi=max(maxi,temp);
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
