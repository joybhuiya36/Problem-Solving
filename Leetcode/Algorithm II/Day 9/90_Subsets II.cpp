class Solution {
public:
vector<vector<int>> ans;
vector<int> v;
    void func(int start, vector<int> &nums)
    {
        ans.push_back(v);
        for(int i=start;i<nums.size();i++)
        {
            if(start<i && nums[i-1]==nums[i])
            continue;
            v.push_back(nums[i]);
            func(i+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        func(0,nums);
        return ans;
    }
};
//Hashset
class Solution {
public:
vector<int> v;
vector<vector<int>> ans;
string s="";
unordered_set<string> st;
    void func(int idx, vector<int> &nums)
    {
        if(idx==nums.size())
        {
            if(!st.count(s))
            {
                st.insert(s);
                ans.push_back(v);
            }
            return;
        }
        func(idx+1,nums);
        s+=to_string(nums[idx]);
        v.push_back(nums[idx]);
        func(idx+1,nums);

        if(nums[idx]==10 || (nums[idx]<0 && nums[idx]>-10))
        {
            s.pop_back();
            s.pop_back();
        }
        else if(nums[idx]==-10)
        {
            s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        else s.pop_back();
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        func(0,nums);
        return ans;
    }
};
