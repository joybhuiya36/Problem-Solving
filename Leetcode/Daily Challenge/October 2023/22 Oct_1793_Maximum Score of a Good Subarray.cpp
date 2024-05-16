class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k, j=k, mn=nums[k],rslt=nums[k];
        int l,r;
        while(i>0 || j<n-1)
        {
            l=i>0? nums[i-1] : 0;
            r=j<n-1? nums[j+1] : 0;
            if(l>r)
            {
                i--;
                mn=min(mn,l);
            }
            else
            {
                j++;
                mn=min(mn,r);
            }
            rslt=max(rslt,(j-i+1)*mn);
        }
        return rslt;
    }
};
