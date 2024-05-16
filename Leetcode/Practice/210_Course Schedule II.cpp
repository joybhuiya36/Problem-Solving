class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n);
        int m=pr.size();
        int ind[n];
        memset(ind,0,sizeof(ind));
        for(int i=0;i<m;i++)
        {
            adj[pr[i][1]].push_back(pr[i][0]);
            ind[pr[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            q.push(i);
        }
        int cur;
        vector<int> v;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            v.push_back(cur);
            for(int i=0;i<adj[cur].size();i++)
            {
                if(--ind[adj[cur][i]]==0)
                {
                    q.push(adj[cur][i]);
                }
            }
        }
        if(v.size()==n) return v;
        else return {};
        
    }
};
