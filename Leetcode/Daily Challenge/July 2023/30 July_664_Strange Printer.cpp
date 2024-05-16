class Solution {
public:
//vector<vector<int>> dp;
int dp[101][101];
	int prntr(int l, int r, string &s)
    {
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int i=l+1;
        while(i<=r && s[l]==s[i])
        i++;
        if(i==r+1) return 1;
        int op1=1+prntr(i,r,s);
        int op2=INT_MAX;
        for(int j=i;j<=r;j++)
        {
            if(s[l]==s[j])
            {
                int ans=prntr(i,j-1,s)+prntr(j,r,s);
                op2=min(ans,op2);
            }
        }
        return dp[l][r]=min(op1,op2);
    }
    int strangePrinter(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        //dp.resize(n+1, vector<int>(n+1,-1));
        return prntr(0,n-1,s);
    }
};
