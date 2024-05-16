class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int totaltime=0, n=garbage.size();
        for(int i=1;i<travel.size();i++)
        travel[i]+=travel[i-1];
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            totaltime+=garbage[i].length();
            for(auto &c:garbage[i])
            mp[c]=i;
        }
        for(auto &it:mp)
        {
            n=it.second;
            if(n==0) continue;
            totaltime+=travel[n-1];
        }
        return totaltime;
    }
};
