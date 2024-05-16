class Solution {
public:
    int game(int alice, int i, int m, vector<int> &piles, vector<vector<vector<int>>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[alice][i][m]!=-1)
        return dp[alice][i][m];
        int total=0, ans= alice==1? 0:INT_MAX;
        for(int x=1;x<=2*m;x++)
        {
            if(i+x-1==n) break;
            total+=piles[i+x-1];
            if(alice==1) //Alice turns
            {
                ans=max(ans,total+game(!alice,i+x,max(m,x),piles,dp,n));
            }
            else //Bob turns
            {
                ans=min(ans,game(!alice,i+x,max(m,x),piles,dp,n));
            }
        }
        return dp[alice][i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return game(1,0,1,piles,dp,n);
    }
};
