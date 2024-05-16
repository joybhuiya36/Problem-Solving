class Solution {
public:
    int finder(int node,vector<int> &parent)
    {
        if(node==parent[node])
        return node;
        return parent[node]=finder(parent[node],parent);
    }
    bool union_join(int &a, int &b,vector<int> &rank, vector<int> &parent)
    {
        int pa=finder(a,parent);
        int pb=finder(b,parent);
        if(pa==pb) return false;
        if(rank[pa]>rank[pb])
        parent[pb]=pa;
        else if(rank[pa]<rank[pb])
        parent[pa]=b;
        else
        {
            parent[pb]=pa;
            rank[pa]++;
        }
        return true;
    }
    bool static greater(vector<int> &a, vector<int> &b)
    {
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        sort(edges.begin(),edges.end(),greater);
        vector<int> ranka(n+1,0);
        vector<int> parenta(n+1);
        vector<int> rankb(n+1,0);
        vector<int> parentb(n+1);
        for(int i=1;i<=n;i++)
        {
            parenta[i]=i;
            parentb[i]=i;
        }
        
        int counta=0,countb=0,rmv=0;
        for(int i=0;i<m;i++)
        {
            if(edges[i][0]==3)
            {
                if(union_join(edges[i][1],edges[i][2],ranka,parenta) && union_join(edges[i][1],edges[i][2],rankb,parentb))
                {
                    counta++;
                    countb++;
                }
                else
                rmv++;
                
            }
            else if(edges[i][0]==2)
            {
                if(union_join(edges[i][1],edges[i][2],rankb,parentb))
                countb++;
                
                else
                rmv++;
                
            }
            else
            {
                if(union_join(edges[i][1],edges[i][2],ranka,parenta))
                counta++;
                
                else
                rmv++;
                
            }
        }
        if(counta==n-1 && countb==n-1)
        return rmv;
        return -1;
    }
};
