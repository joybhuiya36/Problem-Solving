class Solution {
public:
int sum=0;
    void combi(int idx, vector<int> &can, int &tar,vector<int> &v, vector<vector<int>> &ans)
    {
        if(sum==tar)
        {
            ans.push_back(v);
            return;
        }
        if(idx==can.size())
        return;
        for(int i=idx;i<can.size();i++)
        {
            sum+=can[i];
            if(sum>tar)
            {
                sum-=can[i];
                break;
            }
            v.push_back(can[i]);
            combi(i,can,tar,v,ans);
            sum-=can[i];
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(can.begin(),can.end());
        combi(0,can,tar,v,ans);
        return ans;
    }
};
