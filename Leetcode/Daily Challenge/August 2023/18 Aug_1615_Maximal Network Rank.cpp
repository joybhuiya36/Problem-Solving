class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        int adj[n][n];
        int ind[n];
        memset(ind,0,sizeof(ind));
        memset(adj,0,sizeof(adj));
        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]][roads[i][1]]=1;
            adj[roads[i][1]][roads[i][0]]=1;
            ind[roads[i][0]]++;
            ind[roads[i][1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(adj[i][j]==0)
                ans=max(ans,ind[i]+ind[j]);
                else
                ans=max(ans,ind[i]+ind[j]-1);
            }
        }
        return ans;
    }
};
