//Topological Sort Using Kahn's Algorithm
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& gph) {
        int n=gph.size();
        vector<vector<int>> adj(n);
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<gph[i].size();j++)
            {
                adj[gph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> v;
        int cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                if(--indegree[adj[cur][i]]==0)
                q.push(adj[cur][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            v.push_back(i);
        }
        return v;
    }
};
