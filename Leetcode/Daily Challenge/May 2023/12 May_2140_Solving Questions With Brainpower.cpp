//DP
//Memorization
class Solution {
public:
	long long points(int i, vector<vector<int>> &q, vector<long long> &dp, int &n)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=max(points(i+1,q,dp,n),q[i][0]+points(i+1+q[i][1],q,dp,n));
        
    }
    long long mostPoints(vector<vector<int>>& qus) {
        int n=qus.size();
        vector<long long> dp(n,-1);
        return points(0,qus,dp,n);
    }
};
//Tabulation
class Solution {
public:
    long long mostPoints(vector<vector<int>>& qus) {
        int n=qus.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i+1+qus[i][1]<n)
            dp[i]=max(dp[i+1],qus[i][0]+dp[i+1+qus[i][1]]);
            else dp[i]=max(dp[i+1],(long long)qus[i][0]);
        }
        return dp[0];
    }
};
