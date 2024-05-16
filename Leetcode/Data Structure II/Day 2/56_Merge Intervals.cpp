class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intvl) {
        sort(intvl.begin(),intvl.end());
        vector<vector<int>> ans;
        ans.push_back({intvl[0][0],intvl[0][1]});
        for(int i=1;i<intvl.size();i++)
        {
            if(ans[ans.size()-1][1]>=intvl[i][0])
            {
                if(ans[ans.size()-1][1]<intvl[i][1])
                ans[ans.size()-1][1]=intvl[i][1];
            }
            else
            ans.push_back({intvl[i][0],intvl[i][1]});
        }
        return ans;
    }
};
//Standard way of vector back() and push
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intvl) {
        sort(intvl.begin(),intvl.end());
        vector<vector<int>> ans;
        ans.push_back(intvl[0]);
        for(int i=1;i<intvl.size();i++)
        {
            if(ans.back()[1]>=intvl[i][0])
            {
                if(ans.back()[1]<intvl[i][1])
                ans.back()[1]=intvl[i][1];
            }
            else
            ans.push_back(intvl[i]);
        }
        return ans;
    }
};
