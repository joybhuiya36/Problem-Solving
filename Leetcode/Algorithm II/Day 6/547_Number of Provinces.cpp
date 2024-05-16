class Solution {
public:
    void dfs(int i, vector<vector<int>> &isCon, vector<bool> &visit)
    {
        visit[i]=true;
        for(int j=0;j<isCon[i].size();j++)
        {
            if(visit[j]==false && isCon[i][j]==1)
            dfs(j,isCon,visit);
        }
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int n=isCon.size(),count=0;
        vector<bool> visit(n);
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                count++;
                dfs(i,isCon,visit);
            }
        }
        return count;
    }
};
//Or
class Solution {
public:
    void dfs(int i, vector<vector<int>> &list, vector<bool> &visit)
    {
        visit[i]=true;
        for(int j=0;j<list[i].size();j++)
        {
            if(visit[list[i][j]]==false)
            dfs(list[i][j],list,visit);
        }
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int n=isCon.size(),count=0;
        vector<vector<int>> list(n);
        vector<bool> visit(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isCon[i][j]==1 && i!=j)
                list[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                count++;
                dfs(i,list,visit);
            }
        }
        return count;
    }
};
