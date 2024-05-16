class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n3=INT_MIN;
        int n=nums.size();
        stack<int> stk;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<n3)
            return true;
            while(!stk.empty() && nums[i]>stk.top())
            {
                n3=stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
