class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[paths[i][0]]=1;
            mp[paths[i][1]]+=0;
        }
        for(auto &it:mp)
        {
            if(it.second==0)
            return it.first;
        }
        return "";
    }
};
