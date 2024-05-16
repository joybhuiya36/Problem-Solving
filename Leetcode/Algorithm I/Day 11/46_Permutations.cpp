//Optimal by swapping
class Solution {
public:
vector<vector<int>> ans;
    void permu(int idx, vector<int> &nums)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            permu(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permu(0,nums);
        return ans;
    }
};
//By 'used' hash to remember the used values
class Solution {
public:
vector<bool> used;
vector<int> v;
vector<vector<int>> ans;
    void permu(vector<int> & nums)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==false)
            {
                v.push_back(nums[i]);
                used[i]=true;
                permu(nums);
                v.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),false);
        permu(nums);
        return ans;
    }
};
