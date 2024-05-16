class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,maj1,maj2;
        for(auto &num:nums)
        {
            if(num==maj1)
            c1++;
            else if(num==maj2)
            c2++;
            else if(c1==0)
            {
                maj1=num; c1++;
            }
            else if(c2==0)
            {
                maj2=num; c2++;
            }
            else
            {
                c1--; c2--;
            }
        }
        c1=0; c2=0;
        for(auto &num:nums)
        {
            if(num==maj1)
            c1++;
            else if(num==maj2)
            c2++;
        }
        int n=nums.size();
        vector<int> v;
        if(c1>n/3)
        v.push_back(maj1);
        if(c2>n/3)
        v.push_back(maj2);
        return v;
    }
};
