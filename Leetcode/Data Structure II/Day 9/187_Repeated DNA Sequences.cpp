class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=10)
        return {};
        unordered_map<string,int> mp;
        vector<string> v;
        for(int i=0; i<s.size()-9; i++)
        mp[s.substr(i,10)]++;
        for(auto &it:mp)
        if(it.second>1)
        v.push_back(it.first);
        return v;
    }
};
