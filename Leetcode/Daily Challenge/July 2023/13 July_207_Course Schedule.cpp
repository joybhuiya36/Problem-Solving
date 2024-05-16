//Topological Sort Using Kahn's Algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        int m=pr.size();
        vector<vector<int>> adj(n);
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<m;i++)
        {
            adj[pr[i][1]].push_back(pr[i][0]);
            indegree[pr[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            n--;
            for(int i=0;i<adj[cur].size();i++)
            {
                if(--indegree[adj[cur][i]]==0)
                q.push(adj[cur][i]);
            }
        }
        return n==0? true : false;
    }
};
