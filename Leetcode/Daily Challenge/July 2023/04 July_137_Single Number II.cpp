class Solution {
public:
    int getbit(int &pos, int &n)
    {
        return ((n>>pos)&1);
    }
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),sum,ans=0;
        for(int i=0;i<32;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=getbit(i,nums[j]);
            }
            if(sum%3!=0)
            {
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};
