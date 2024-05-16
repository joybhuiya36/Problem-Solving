class Solution {
public:
    vector<bool> visit;
    vector<vector<int>> v;
    int nodes=0;
    void dfs(int node, int &nodes)
    {
        visit[node]=true;
        for(int i=0;i<v[node].size();i++)
        {
            if(visit[v[node][i]]==false)
            {
                nodes++;
                dfs(v[node][i],nodes);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()<n-1)
        return -1;
        visit.resize(n,false);
        v.resize(n);
        for(int i=0;i<con.size();i++)
        {
            v[con[i][0]].push_back(con[i][1]);
            v[con[i][1]].push_back(con[i][0]);
        }
        for(int i=0;i<n;i++)
        dfs(i,nodes);
        return n-nodes-1;
    }
};
