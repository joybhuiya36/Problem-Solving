class Solution {
public:
    bool dfs(int idx, int clr, vector<vector<int>> &gp, vector<int> &color)
    {
        if(color[idx]!=-1)
        {
            if(color[idx]==clr)
            return true;
            else return false;
        }
        color[idx]=clr;
        for(int i=0;i<gp[idx].size();i++)
        {
            if(dfs(gp[idx][i],!clr,gp,color)==false)
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1 && dfs(i,0,graph,color)==false)
            return false;
        }
        return true;
    }
};
