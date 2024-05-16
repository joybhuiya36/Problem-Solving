class Solution {
public:
    void dfs(string u, string &v, double prd, unordered_set<string> &visit, unordered_map<string,vector<pair<string,double>>> &adj, double &output)
    {
        if(u==v)
        {
            output=prd;
            return;
        }
        visit.insert(u);
        for(auto &w:adj[u])
        {
            if(!visit.count(w.first))
            dfs(w.first,v,prd*w.second,visit,adj,output);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>> adj;
        unordered_set<string> mp;
        vector<double> ans(q.size(),-1.0);
        double output;
        string u,v;
        for(int i=0;i<eq.size();i++)
        {
            u=eq[i][0]; v=eq[i][1];
            mp.insert(u); mp.insert(v);
            adj[u].push_back({v,val[i]});
            adj[v].push_back({u,1.0/val[i]});
        }
        for(int i=0;i<q.size();i++)
        {
            output=-1.0;
            u=q[i][0]; v=q[i][1];
            if(!mp.count(u) || !mp.count(v))
            continue;
            unordered_set<string> visit;
            dfs(u,v,1.0,visit,adj,output);
            ans[i]=output;
        }
        return ans;
    }
};
