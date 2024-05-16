//Total 3 Solutions

//Swap and hashset
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
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            continue;
            st.insert(nums[i]);
            swap(nums[idx],nums[i]);
            permu(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permu(0,nums);
        return ans;
    }
};
//Optimal
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
            if(used[i]==true || (i>0 && nums[i]==nums[i-1] && used[i-1]==false))
            continue;
            v.push_back(nums[i]);
            used[i]=true;
            permu(nums);
            v.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(),false);
        sort(nums.begin(),nums.end());
        permu(nums);
        return ans;
    }
};
//My First Solution
class Solution {
public:
vector<bool> used;
vector<int> v;
vector<vector<int>> ans;
string s="";
unordered_set<string> st;
    void permu(vector<int> & nums)
    {
        if(v.size()==nums.size())
        {
            if(!st.count(s))
            {
                st.insert(s);
                ans.push_back(v);
            }
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==false)
            {
                s+=to_string(nums[i]);
                v.push_back(nums[i]);
                used[i]=true;
                permu(nums);
                if(nums[i]==10 || (nums[i]<0 && nums[i]>-10))
                {
                    s.pop_back();
                    s.pop_back();
                }
                else if(nums[i]==-10)
                {
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                }
                else s.pop_back();

                v.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(),false);
        sort(nums.begin(),nums.end());
        permu(nums);
        return ans;
    }
};
