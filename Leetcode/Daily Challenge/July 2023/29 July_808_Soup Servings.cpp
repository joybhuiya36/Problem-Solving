class Solution {
public:
vector<pair<int,int>> srv={{100,0},{75,25},{50,50},{25,75}};
	double serve(int a, int b, vector<vector<double>> &dp)
    {
        if(a<=0 && b<=0)
        return 0.5;
        else if(a<=0)
        return 1.0;
        else if(b<=0)
        return 0.0;
        if(dp[a][b]!=-1.0)
        return dp[a][b];
        double pb=0.0;
        for(auto &i:srv)
        {
            pb+=serve(a-i.first,b-i.second,dp);
        }
        return dp[a][b]=0.25*pb;
    }
    double soupServings(int n) {
        if(n>=4000) return 1.0;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
        return serve(n,n,dp);
    }
};
