class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int r=n-1;r>=0;r--)
        {
            for(int c=0;c<nums[r].size();c++)
            mp[r+c].push_back(nums[r][c]);
        }
        vector<int> v;
        for(int i=0;mp.count(i);i++)
        {
            for(auto &j:mp[i])
            v.push_back(j);
        }
        return v;
    }
};
