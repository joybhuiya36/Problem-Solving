class Solution {
public:
vector<int> v;
vector<vector<int>> ans;
    void func(int idx, vector<int> &nums)
    {
        if(idx==nums.size())
        {
            ans.push_back(v);
            return;
        }
        func(idx+1,nums);
        v.push_back(nums[idx]);
        func(idx+1,nums);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        func(0,nums);
        return ans;
    }
};
