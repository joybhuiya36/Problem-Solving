class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_mx=INT_MIN, b_mx=INT_MIN, prd=1, prd2=1, n=nums.size();
        for(int i=0;i<n;i++)
        {
            prd*=nums[i];
            f_mx=max(f_mx,prd);
            prd2*=nums[n-1-i];
            b_mx=max(b_mx,prd2);
            if(prd==0) prd=1;
            if(prd2==0) prd2=1;
        }
        return max(f_mx,b_mx);
    }
};
//or
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int ma = ans;
        int mi = ans;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(ma,mi);
            }
            ma = max(nums[i], ma*nums[i] );
            mi = min(nums[i], mi*nums[i] );
            ans = max(ans,ma);
        }
        return ans;
    }
};
