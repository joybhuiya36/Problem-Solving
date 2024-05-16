class Solution {
public:
vector<vector<int>> dp;
vector<vector<int>> list;
bool loop=false;
vector<bool> visit;
vector<bool> stk;
    void dfs(int node, string &colors)
    {
        visit[node]=true;
        stk[node]=true;
        if(list[node].size()>0)
        {
            for(int i=0;i<list[node].size();i++)
            {
                if(visit[list[node][i]]==false)
                {
                    dfs(list[node][i],colors);
                    stk[list[node][i]]=false;
                }
                else if(stk[list[node][i]]==true)
                loop=true;
                for(int j=0;j<26;j++)
                {
                    dp[node][j]=max(dp[node][j],dp[list[node][i]][j]);
                }
            }
            dp[node][colors[node]-'a']++;
        }
        else
        {
            dp[node][colors[node]-'a']++;
        }
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length(), mx=-1;
        dp.resize(n,vector<int>(26,0));
        list.resize(n);
        visit.resize(n,false);
        stk.resize(n,false);

        for(int i=0;i<edges.size();i++)
        list[edges[i][0]].push_back(edges[i][1]);

        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                dfs(i,colors);
                if(loop) return -1;
                stk[i]=false;
                for(int j=0;j<26;j++)
                {
                    if(dp[i][j]!=0 && dp[i][j]>mx)
                    mx=dp[i][j];
                }
            }
        }
        return mx;
    }
};
