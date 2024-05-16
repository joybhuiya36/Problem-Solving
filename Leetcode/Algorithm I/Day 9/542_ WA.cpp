class Solution {
public:
vector<vector<int>> dp;
vector<vector<int>> visit;
int m,n;
    int dfs(int i, int j, vector<vector<int>> &mat)
    {
        if(mat[i][j]==0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(mat[i][j]!=0)
        visit[i][j]=1;
        cout<<i<<" ij "<<j<<endl;
        int u=100000,d=100000,l=100000,r=100000;
        if(j>0 && visit[i][j-1]==0)
        l=dfs(i,j-1,mat)+1;
        if(i>0 && visit[i-1][j]==0)
        u=dfs(i-1,j,mat)+1;
        if(j<n-1 && visit[i][j+1]==0)
        r=dfs(i,j+1,mat)+1;
        if(i<m-1 && visit[i+1][j]==0)
        d=dfs(i+1,j,mat)+1;
        cout<<i<<" ij "<<j<<" -> "<<d<<" "<<u<<" "<<l<<" "<<r<<endl;
        dp[i][j]=min(min(d,u),min(l,r));
        return dp[i][j];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size(); n=mat[0].size();
        dp.resize(m,vector<int>(n,-1));
        visit.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=dfs(i,j,mat);
            }
        }
        return dp;
    }
};
