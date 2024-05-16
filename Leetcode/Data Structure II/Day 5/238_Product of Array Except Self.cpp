class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prd=1, zero=0;
        for(int &i:nums)
        {
            if(i!=0)
            prd*=i;
            else zero++;
        }
        if(zero>1)
        for(int &i:nums)
        i=0;
        else if(zero==1)
        for(int &i:nums)
        {
            if(i!=0)
            i=0;
            else i=prd;
        }
        else
        for(int &i:nums)
        {
            i=prd/i;
        }
        return nums;
    }
};
