class Solution {
public:
vector<bool> visit;
int count,repeat=-1;
    void dfs(int node, vector<int> &list)
    {
        if(list[node]==-1)
        {
            visit[node]=true;
            return;
        }
        if(visit[node]==true)
        {
            repeat=node;
            return;
        }
        visit[node]=true;
        dfs(list[node],list);
        if(repeat!=-1)
        {
            count++;
            if(repeat==node)
            repeat=-1;
        }
    }
    int longestCycle(vector<int>& edges) {
        int mx=0;
        visit.resize(edges.size(),false);
        for(int i=0;i<edges.size();i++)
        {
            count=0;
            if(visit[i]==false)
            dfs(i,edges);
            if(repeat!=-1)
            {
                repeat=-1;
                count=0;
            }
            if(count>mx)
            mx=count;
        }
        if(mx==0)
        return -1;
        else
        return mx;
    }
};
