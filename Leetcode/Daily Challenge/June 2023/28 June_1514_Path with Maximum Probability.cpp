//Dijkstra
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        double prb[n];
        memset(prb,0,sizeof(prb));
        prb[start]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(pq.size())
        {
            auto cur=pq.top();
            pq.pop();
            for(int i=0;i<adj[cur.second].size();i++)
            {
                auto nxt=adj[cur.second][i];
                if(nxt.second*cur.first>prb[nxt.first])
                {
                    prb[nxt.first]=nxt.second*cur.first;
                    pq.push({prb[nxt.first],nxt.first});
                }
            }
        }
        return prb[end];
    }
};
