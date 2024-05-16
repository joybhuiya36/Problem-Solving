class Solution {
public:
vector<int> rank;
vector<int> parent;
    int finder(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=finder(parent[node]);
    }
    void union_join(int &a, int &b)
    {
        int pa=finder(a);
        int pb=finder(b);
        if(pa==pb) return;
        if(rank[pa]>rank[pb])
        parent[pb]=pa;
        else if(rank[pa]<rank[pb])
        parent[pa]=b;
        else
        {
            parent[pb]=pa;
            rank[pa]++;
        }
    }
    bool static compare(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& q) {
        int qn=q.size();
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent.push_back(i);
        for(int i=0;i<qn;i++)
        q[i].push_back(i);
        sort(edgeList.begin(),edgeList.end(),compare);
        sort(q.begin(),q.end(),compare);
        vector<bool> ans(qn);
        int j=0,t;
        for(int i=0;i<qn;i++)
        {
            t=q[i][2];
            while(j<edgeList.size() && t>edgeList[j][2])
            {
                union_join(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(finder(q[i][0])==finder(q[i][1]))
            ans[q[i][3]]=true;
            else ans[q[i][3]]=false;
        }
        return ans;
    }
};
