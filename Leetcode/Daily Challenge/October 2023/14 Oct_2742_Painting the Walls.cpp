class Solution {
public:
int dp[501][501];
int n;
	int solve(int i, int rm, vector<int> &cost, vector<int> &time) // rm= remaining wall
    {
        if(rm<=0)
        return 0;
        if(i>=n) return 1e9;
        if(dp[i][rm]!=-1) return dp[i][rm];
        int taken= cost[i]+solve(i+1,rm-(1+time[i]),cost,time);
        int not_taken=solve(i+1,rm,cost,time);
        return dp[i][rm]=min(taken,not_taken);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=time.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,cost,time);
    }
};
