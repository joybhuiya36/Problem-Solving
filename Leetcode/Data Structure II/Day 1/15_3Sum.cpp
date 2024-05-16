//Optimized
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size(), ptr, left, right;
        sort(nums.begin(),nums.end());
        if(nums[0]>0) return ans;		//if the first value is positive, then it is impossible to 3sum=0
        for(int ptr=0;ptr<n-2;ptr++)
        {
            if(ptr-1>=0 && nums[ptr]==nums[ptr-1])
            continue;
            left=ptr+1; right=n-1;
            while(left<right)
            {
                if(nums[ptr]+nums[left]+nums[right]>0)
                right--;
                else if(nums[ptr]+nums[left]+nums[right]<0)
                left++;
                else
                {
                    ans.push_back({nums[ptr],nums[left],nums[right]});
                    left++;
                    while(left<right && nums[left]==nums[left-1])
                    left++;
                    right--;
                    while(left<right && nums[right]==nums[right+1])
                    right--;
                }
            }
        }
        return ans;
    }
};
//Hashset
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<string> st;
        int n=nums.size(), ptr, left, right;
        sort(nums.begin(),nums.end());
        for(int ptr=0;ptr<n-2;ptr++)
        {
            left=ptr+1; right=n-1;
            while(left<right)
            {
                if(nums[ptr]+nums[left]+nums[right]>0)
                right--;
                else if(nums[ptr]+nums[left]+nums[right]<0)
                left++;
                else if(nums[ptr]+nums[left]+nums[right]==0)
                {
                    string s=to_string(nums[ptr])+to_string(nums[left])+to_string(nums[right]);
                    if(!st.count(s))
                    ans.push_back({nums[ptr],nums[left],nums[right]});
                    st.insert(s);
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
