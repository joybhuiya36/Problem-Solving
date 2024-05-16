class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.size(),-1);
        stack<int> stk;
        for(int i=0;i<nums.size();i++)
        {
            while(!stk.empty() && nums[i]>nums[stk.top()])
            {
                v[stk.top()]=nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        if(stk.size()==1) return v;
        for(int i=0;i<nums.size();i++)
        {
            while(!stk.empty() && nums[i]>nums[stk.top()])
            {
                v[stk.top()]=nums[i];
                stk.pop();
            }
            if(stk.size()==1) return v;
        }
        return v;
    }
};
