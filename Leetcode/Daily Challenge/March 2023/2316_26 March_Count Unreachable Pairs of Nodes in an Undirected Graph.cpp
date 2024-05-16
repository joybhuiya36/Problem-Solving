class Solution {
public:
vector<vector<int>> list;
vector<int> visit;
long long count=0, total_pair=0;
int visited=0;
    void dfs(int node)
    {
        visit[node]=true;
        for(int &i:list[node])
        {
            if(visit[i]==false)
            {
                count++;
                dfs(i);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        list.resize(n);
        visit.resize(n,false);
        for(int i=0;i<edges.size();i++)
        {
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                count++;
                dfs(i);
                visited+=count;
                total_pair+=(n-visited)*count;
                count=0;
            }
        }
        return total_pair;
    }
};
