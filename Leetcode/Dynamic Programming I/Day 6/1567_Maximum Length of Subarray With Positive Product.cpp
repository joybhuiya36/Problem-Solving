class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int flen=0,blen=0,prd=1,prd2=1,n=nums.size(),ans=0;
        bool z=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) prd*=1;
            else if(nums[i]<0) prd*=-1;
            else
            {
                flen=0;
                prd=1;
                z=true;
            }
            if(!z) flen++;
            else z=false;
            if(nums[n-1-i]>0) prd2*=1;
            else if(nums[n-1-i]<0) prd2*=-1;
            else
            {
                blen=0;
                prd2=1;
                z=true;
            }
            if(!z) blen++;
            else z=false;
            if(prd>0)
            ans=max(ans,flen);
            if(prd2>0)
            ans=max(ans,blen);
        }
        return ans;
    }
};
