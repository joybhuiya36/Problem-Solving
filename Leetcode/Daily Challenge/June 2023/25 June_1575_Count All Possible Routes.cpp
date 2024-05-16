//DP
//Memorization
class Solution {
public:
int dp[101][201];
int mod=1e9+7;
    int routes(int cur, int &finish, int fuel, vector<int> &loc, int &n)
    {
        if(fuel<0) return 0;
        if(dp[cur][fuel]!=-1)
        return dp[cur][fuel];
        int total= cur==finish? 1:0;
        for(int i=0;i<n;i++)
        {
            if(i==cur) continue;
            total=(total+routes(i,finish,fuel-abs(loc[cur]-loc[i]),loc,n))%mod;
        }
        return dp[cur][fuel]=total;
    }
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        int n=loc.size();
        memset(dp,-1,sizeof(dp));
        return routes(start,finish,fuel,loc,n);
    }
};
//Tabulation
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));
        for(int i = 0; i<=fuel; i++) {
            dp[finish][i] = 1;
        }

        int ans = 0;
        for (int j = 0; j <= fuel; j++) {
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    if (abs(locations[i] - locations[k]) <= j) {
                        dp[i][j] = (dp[i][j] + dp[k][j - abs(locations[i] - locations[k])]) %
                                   1000000007;
                    }
                }
            }
        }

        return dp[start][fuel];
    }
};
