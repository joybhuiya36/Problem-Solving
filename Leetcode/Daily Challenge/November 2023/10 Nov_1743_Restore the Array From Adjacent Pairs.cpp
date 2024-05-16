class Solution {
public:
unordered_map<int,vector<int>> adj;
vector<int> ans;
int ch;
    void dfs(int x, int parent)
    {
        ans.push_back(x);
        for(int i=0;i<adj[x].size();i++)
        {
            ch=adj[x][i];
            if(ch!=parent)
        	dfs(ch,x);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& pair) {
        unordered_map<int,int> mp;
        int n=pair.size();
        int x,y;
        for(int i=0;i<n;i++)
        {
            x=pair[i][0]; y=pair[i][1];
            if(++mp[x]==2)
            mp.erase(x);
            if(++mp[y]==2)
            mp.erase(y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        auto it=mp.begin();
        dfs(it->first,999999);
        return ans;
    }
};
