//Tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2,0);
        for(int i=cost.size()-1;i>=0;i--)
        {
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
//Space Optimization (2 Approaches)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]=cost[i]+min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
        
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0,b=0,temp;
        for(int i=cost.size()-1;i>=0;i--)
        {
            temp=a;
            a=cost[i]+min(a,b);
            b=temp;
        }
        return min(a,b);
    }
};
//Memorization
class Solution {
public:
    int climb(int idx, vector<int> &cost, vector<int> &dp)
    {
        if(idx>=cost.size())
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        return dp[idx]=cost[idx]+min(climb(idx+1,cost,dp),climb(idx+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(climb(0,cost,dp),climb(1,cost,dp));
    }
};
