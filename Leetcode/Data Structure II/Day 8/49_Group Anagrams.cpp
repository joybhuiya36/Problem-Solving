class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> v;
        for(string &w:strs)
        {
            string str=w;
            sort(str.begin(),str.end());
            mp[str].push_back(w);
        }
        for(auto &it:mp)
        v.push_back(it.second);
        return v;
    }
};
