class Solution {
public:
unordered_map<string,vector<string>> adj;
int n;
vector<string> rslt;
	bool dfs(string fcity, vector<string> &path)
  {
    path.push_back(fcity);
    if(path.size()==n+1)
    {
      rslt=path;
      return true;
    }
    vector<string> &neighbors=adj[fcity];
    string tcity;
    for(int i=0;i<neighbors.size();i++)
    {
      tcity=neighbors[i];
      neighbors.erase(neighbors.begin()+i);
      if(dfs(tcity,path))
      return true;
      neighbors.insert(neighbors.begin()+i,tcity);
    }
    path.pop_back();
    return false;
  }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n=tickets.size();
        for(auto &t:tickets)
        {
          adj[t[0]].push_back(t[1]);
        }
        for(auto &v:adj)
        {
          sort(begin(v.second),end(v.second));
        }
        vector<string> path;
        string airport="JFK";
        dfs(airport,path);
        return rslt;
    }
};
