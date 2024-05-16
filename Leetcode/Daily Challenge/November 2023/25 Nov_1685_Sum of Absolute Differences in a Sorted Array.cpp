class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0;i<n;i++)
        sum+=nums[i];
        int prefix=0, pre;
        for(int i=0;i<n;i++)
        {
            pre=nums[i];
            nums[i]=(pre*i)-prefix+(sum-prefix-pre)-(pre*(n-i-1));
            prefix+=pre;
        }
        return nums;
    }
};
