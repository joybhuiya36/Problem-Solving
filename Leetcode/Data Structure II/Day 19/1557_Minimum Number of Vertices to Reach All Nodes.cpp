class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v;
        vector<bool> indegree(n,false);
        for(int i=0;i<edges.size();i++)
        indegree[edges[i][1]]=true;
        for(int i=0;i<n;i++)
        if(indegree[i]==false)
        v.push_back(i);
        return v;
    }
};
