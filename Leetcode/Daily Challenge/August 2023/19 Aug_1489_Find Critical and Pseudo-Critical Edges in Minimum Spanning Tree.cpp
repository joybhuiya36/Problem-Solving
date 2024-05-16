class dsu {
public:
    vector<int> parent;
    vector<int> rank;
    dsu(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a, int b)
    {
        int parent_a=find(a);
        int parent_b=find(b);
        if(rank[parent_a]>rank[parent_b])
        parent[parent_b]=parent_a;
        else if(rank[parent_a]<rank[parent_b])
        parent[parent_a]=parent_b;
        else
        {
            parent[parent_b]=parent_a;
            rank[parent_a]++;
        }
    }
};
class Solution {
public:
    int MST(vector<vector<int>> &e, int add, int skip, int &node)
    {
        int n=e.size();
        dsu d(node);
        int sum=0;
        int u, v, wt;
        if(add!=-1)
        {
            u=e[add][0]; v=e[add][1]; wt=e[add][2];
            d.Union(u,v);
            sum+=wt;
        }
        
        for(int i=0;i<n;i++)
        {
            if(skip==i)
            continue;
            u=e[i][0]; v=e[i][1]; wt=e[i][2];
            if(d.find(u)!=d.find(v))
            {
                d.Union(u,v);
                sum+=wt;
            }
        }
        for(int i=0;i<node;i++)
        {
            if(d.find(0)!=d.find(i))
            return INT_MAX;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++)
        edges[i].push_back(i);
        sort(edges.begin(),edges.end(),[&](vector<int> &a, vector<int> &b)
        {
            return a[2]<b[2];
        });

        int mst=MST(edges,-1,-1,n);
        cout<<mst<<endl;
        vector<int> c;
        vector<int> pc;
        for(int i=0;i<m;i++)
        {
            if(MST(edges,-1,i,n)>mst)
            {
                c.push_back(edges[i][3]);
            }
            else if(MST(edges,i,-1,n)==mst)
            {
                pc.push_back(edges[i][3]);
            }
        }
        return {c,pc};
    }
};
