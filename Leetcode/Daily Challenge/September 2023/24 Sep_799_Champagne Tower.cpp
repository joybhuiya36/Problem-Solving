//Bottom Up
class Solution {
public:
    double champagneTower(int poured, int qr, int qc) {
        double dp[101][101];
        memset(dp,0.0,sizeof(dp));
        dp[0][0]=double(poured);
        double extra;
        for(int r=0;r<=qr;r++)
        {
            for(int c=0;c<=r;c++)
            {
                extra=(dp[r][c]-1)/2.0;
                if(extra>0)
                {
                    dp[r+1][c]+=extra;
                    dp[r+1][c+1]+=extra;
                }
            }
        }
        return min(1.0,dp[qr][qc]);
    }
};
//Memorization
class Solution {
public:
    double func(int poured, int qrow, int qglass, vector<vector<double>> &dp)
    {
        if(qrow < 0 or qglass < 0)
            return 0;
        
        if(qrow == 0 and qglass == 0)
            return poured;

        if(dp[qrow][qglass] != -1.00)
            return dp[qrow][qglass];

        double left = 0, right = 0;

        left = (func(poured, qrow-1, qglass-1, dp)-1)/2;
        right = (func(poured, qrow-1, qglass, dp)-1)/2;

        if(left < 0) 
            left = 0.0;
        
        if(right < 0) 
            right = 0.0;
        
        return dp[qrow][qglass] = left+right;
    }

    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<vector<double>> dp(101, vector<double> (101, -1));
        return min(1.00, func(poured, query_row, query_glass, dp));
    }
};
