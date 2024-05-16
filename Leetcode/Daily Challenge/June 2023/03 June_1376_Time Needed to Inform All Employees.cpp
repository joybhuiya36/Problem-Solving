//DFS
class Solution {
public:
    int dfs(int root, vector< vector<int> >& v, vector<int>& informTime)
    {
        if(informTime[root]==0)
        return 0;
        int mx=-1;
        for(int i=0;i<v[root].size();i++)
        {
            int mn = dfs(v[root][i],v,informTime)+informTime[root];
            if(mn>mx)
            mx=mn;
        }
        return mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector< vector<int> >v(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            v[manager[i]].push_back(i);
        }
        int mn=dfs(headID,v,informTime);
        return mn;
    }
};
//BFS
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        queue<vector<int>> q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty())
        {
            auto cur=q.front();
            ans=max(ans,cur[1]);
            q.pop();
            for(int i=0;i<adj[cur[0]].size();i++)
            {
                q.push({adj[cur[0]][i],cur[1]+informTime[cur[0]]});
            }
        }
        return ans;
    }
};
