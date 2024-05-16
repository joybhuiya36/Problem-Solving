static const auto init = []{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    return false;
}(); //fast input-output
class Solution {
public:
    int dfs(int root, vector< vector<int> >& v, vector<int>& informTime)
    {
        if(informTime[root]==0)
        return 0;
        int mx=-1;
        for(int i=0;i<v[root].size();i++)
        {
            int mn = dfs(v[root][i],v,informTime)+informTime[root];
            if(mn>mx)
            mx=mn;
        }
        return mx;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector< vector<int> >v(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            v[manager[i]].push_back(i);
        }
        int mn=dfs(headID,v,informTime);
        if(mn==0)
        return informTime[headID];
        return mn;
    }
};
