class Solution {
public:
    int mn=INT_MAX;
    void dfs(int node, vector<vector<pair<int,int>>> &v, vector<bool> &visited)
    {
        visited[node]=true;
        for(int i=0;i<v[node].size();i++)
        {
            if(v[node][i].second<mn) mn=v[node][i].second;
            if(visited[v[node][i].first]==false)
            dfs(v[node][i].first,v,visited);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        if(roads.size()==1)
        return roads[0][2];
        vector<vector<pair<int,int>>> v(n+1);
        vector<bool> visited(n+1,false);
        for(int i=0;i<roads.size();i++)
        {
            v[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        dfs(1,v,visited);
        return mn;
    }
};
