//DP
//Memorization
class Solution {
public:
    int pascal(int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i].size()==j)
        dp[i].push_back(0);
        else
        return dp[i][j];
        if(j==0 || i==j)
        return dp[i][j]=1;
        return dp[i][j]=pascal(i-1,j-1,dp)+pascal(i-1,j,dp);
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        dp[0].push_back(1);
        for(int i=0;i<n;i++)
        pascal(n-1,i,dp);
        return dp;
    }
};
class Solution {
public:
    int pascal(int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        int col=j;
        if(j==0)
        {
            dp[i][j++]=1;
            dp[i][i]=1;
        }
        while(j<i)
        {
            dp[i][j]=pascal(i-1,j-1,dp)+pascal(i-1,j,dp);
            j++;
        }
        return dp[i][col];

    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            dp[i].push_back(-1);
        }
        dp[0][0]=1;
        pascal(n-1,0,dp);
        return dp;
    }
};
//Tabulation
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector< vector<int> >v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                v[i].push_back(1);
                else
                v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            }
        }
        return v;
    }
};
