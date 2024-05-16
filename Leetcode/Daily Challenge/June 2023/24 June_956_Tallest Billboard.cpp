class Solution {
public:
int dp[21][10001];
	int solve(int i, int diff, vector<int> &rods, int &n)
    {
        if(i==n)
        {
            if(diff==0) return 0;
            return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1)
        return dp[i][diff+5000];
        int l1=rods[i]+solve(i+1,diff+rods[i],rods,n);
        int l2=rods[i]+solve(i+1,diff-rods[i],rods,n);
        int not_taken=solve(i+1,diff,rods,n);
        return dp[i][diff+5000]=max(not_taken, max(l1,l2));
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,rods,n)/2;
    }
};
