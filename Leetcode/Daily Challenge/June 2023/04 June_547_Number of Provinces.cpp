//DFS
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
        vector<bool> visit(n,false);
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
//Union Find (Disjoint Set)
class union_set {
    vector<int> parent, rank;
public:
    union_set(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]!=x)
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void make_union(int x, int y)
    {
        int xparent=find(x);
        int yparent=find(y);
        if(rank[xparent]>rank[yparent])
        parent[yparent]=xparent;
        else if(rank[xparent]<rank[yparent])
        parent[xparent]=yparent;
        else
        {
            parent[yparent]=xparent;
            rank[xparent]++;   
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isCon) {
        int n=isCon.size();
        int ans=n;
        union_set u(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isCon[i][j]==1 && u.find(i)!=u.find(j))
                {
                    ans--;
                    u.make_union(i,j);
                }
            }
        }
        return ans;
    }
};
