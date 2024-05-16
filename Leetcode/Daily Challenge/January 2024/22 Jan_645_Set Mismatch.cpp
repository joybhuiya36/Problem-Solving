class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a,b=-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            a=nums[i];
            else if(nums[i]-nums[i-1]==2)
            b=nums[i]-1;
        }
        
        if(nums[0]!=1)
        b=1;
        else if(b==-1)
        b=n;
        return {a,b};
    }
};
