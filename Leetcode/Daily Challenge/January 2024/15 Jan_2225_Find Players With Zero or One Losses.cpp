class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        vector<vector<int>> v(2);
        unordered_set<int> winners,oneMatch,all;
        for(int i=0;i<n;i++)
        {
            if(!all.count(matches[i][0]))
            winners.insert(matches[i][0]);
            if(winners.count(matches[i][1]))
            {
                winners.erase(matches[i][1]);
                oneMatch.insert(matches[i][1]);
            }
            else
            {
            	if(oneMatch.count(matches[i][1]))
                oneMatch.erase(matches[i][1]);
                else if(!all.count(matches[i][1]))
                oneMatch.insert(matches[i][1]);
            }
            all.insert(matches[i][1]);
        }
        for(auto it=winners.begin();it!=winners.end();it++)
        v[0].push_back(*it);
        for(auto it=oneMatch.begin();it!=oneMatch.end();it++)
        v[1].push_back(*it);
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        return v;
    }
};
