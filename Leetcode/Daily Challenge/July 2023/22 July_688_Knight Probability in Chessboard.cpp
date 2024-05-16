class Solution {
public:
int dir[8][2]={{-2,-1},{-2,1},{-1,-2},{1,-2},{-1,2},{1,2},{2,-1},{2,1}};
vector<vector<vector<double>>> dp;
    double recur(int r, int c, int k, int &n)
    {
        if(r<0 || r>n-1 || c<0 ||  c>n-1)
        return 0;
        if(k==0) return 1;
        double sum=0.0;
        if(dp[r][c][k]!=-1)
        return dp[r][c][k];
        for(int i=0;i<8;i++)
        {
            int x=r+dir[i][0];
            int y=c+dir[i][1];
            sum+=recur(x,y,k-1,n);
        }
        return dp[r][c][k]=(double)sum/8.0;
    }
    double knightProbability(int n, int k, int row, int col) {
        dp.resize(n,vector<vector<double>>(n, vector<double>(k+1,-1)));
        return recur(row,col,k,n);
    }
};
