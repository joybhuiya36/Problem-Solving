class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v={{nums[0]}};
        int j=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            {
                if(j<v.size())
                v[j].push_back(nums[i]);
                else v.push_back({nums[i]});
                j++;
            }
            else
            {
                j=1;
                v[0].push_back(nums[i]);
            }
        }
        return v;
    }
};
