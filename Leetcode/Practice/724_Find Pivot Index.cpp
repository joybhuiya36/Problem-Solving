class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rsum[n];
        int lsum=0;
        rsum[n-1]=nums.back();
        for(int i=n-2;i>=0;i--)
        {
            rsum[i]=rsum[i+1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            lsum+=nums[i];
            if(lsum==rsum[i])
            return i;
        }
        return -1;
    }
};
