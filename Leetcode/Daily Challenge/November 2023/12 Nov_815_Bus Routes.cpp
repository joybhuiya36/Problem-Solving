class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
        if(src==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<routes[i].size();j++)
            adj[routes[i][j]].push_back(i);
        }
        queue<int> q;
        int visit[501];
        memset(visit,0,sizeof(visit));
        n=adj[src].size();
        for(int i=0;i<n;i++)
        {
            q.push(adj[src][i]);
        	visit[adj[src][i]]=1;
    	}
        int ans=1;
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                src=q.front();
                q.pop();
                for(auto &stop:routes[src])
                {
                    if(stop==target)
                    return ans;
                    for(auto &bus:adj[stop])
                    {
                        if(visit[bus]==0)
                        {
                            q.push(bus);
                            visit[bus]=1;
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
