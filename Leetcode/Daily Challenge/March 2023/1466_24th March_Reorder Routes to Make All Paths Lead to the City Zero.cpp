class Solution {
public:
vector<vector<pair<int,int>>> list;
vector<bool> visit;
int count=0;
    void dfs(int city)
    {
        visit[city]=true;
        for(int i=0;i<list[city].size();i++)
        {
            if(visit[list[city][i].first]==false)
            {
                count+=list[city][i].second;
                dfs(list[city][i].first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        list.resize(n);
        visit.resize(n,false);
        for(int i=0;i<con.size();i++)
        {
            list[con[i][0]].push_back({con[i][1],1});
            list[con[i][1]].push_back({con[i][0],0});
        }
        dfs(0);
        return count;
    }
};
