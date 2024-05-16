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
int main()
{
	union_set u(n);
}
