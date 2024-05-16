class Solution {
public:
    void dfs(int i, vector<bool> &visit, vector<vector<int>> &adj,int &count)
    {
        visit[i]=true;
        count++;
        for(int j=0;j<adj[i].size();j++)
        {
            if(visit[adj[i][j]]==false)
            dfs(adj[i][j],visit,adj,count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bm) {
        int n=bm.size();
        long x,y,r;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                x=bm[i][0]-bm[j][0]; y=bm[i][1]-bm[j][1]; r=bm[i][2];
                if(x*x+y*y<=r*r)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int mx=1;
        for(int i=0;i<n;i++)
        {
            vector<bool> visit(n,false);
            int count=0;
            dfs(i,visit,adj,count);
            mx=max(mx,count);
        }
        return mx;
    }
};
