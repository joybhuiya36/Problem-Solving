class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        int n=gp.size();
        vector<vector<int>> v(n+1),ans;
        for(int i=0;i<n;i++)
        {
            v[gp[i]].push_back(i);
            if(v[gp[i]].size()==gp[i])
            {
                ans.push_back(v[gp[i]]);
                v[gp[i]]={};
            }
        }
        return ans;
    }
};
