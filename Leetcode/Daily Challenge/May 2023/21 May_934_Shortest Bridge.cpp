class Solution {
public:
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
queue<pair<int,int>> q;
    bool bound(int &i, int &j, int &n)
    {
        if(i>=0 && i<n && j>=0 && j<n)
        return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>> &g, int &n)
    {
        if(!bound(i,j,n) || g[i][j]==2 || g[i][j]==0)
        return;
        g[i][j]=2;
        q.push({i,j});
        for(int k=0;k<4;k++)
        dfs(i+x[k],j+y[k],g,n);
    }
    int bfs(vector<vector<int>> &g, int &n)
    {
        int i,j,t,lvl=0,r,c;
        cout<<q.size();
        while(!q.empty())
        {
            t=q.size();
            while(t--)
            {
                i=q.front().first; j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    r=i+x[k]; c=j+y[k];
                    if(bound(r,c,n) && g[r][c]!=2)
                    {
                        if(g[r][c]==1)
                        return lvl;
                        g[r][c]=2;
                        q.push({r,c});
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,n);
                    return bfs(grid,n);
                }
            }
        }
        return -1;
    }
};
