class Solution {
public:
vector<int> v;
	void dfs(int node, vector<vector<int>> &gph, vector<vector<int>> &ans, int n)
    {
        v.push_back(node);
        if(node==n-1)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<gph[node].size();i++)
        {
            dfs(gph[node][i],gph,ans,n);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& gph) {
        int n=gph.size();
        vector<vector<int>> ans;
        dfs(0,gph,ans,n);
        return ans;
    }
};
