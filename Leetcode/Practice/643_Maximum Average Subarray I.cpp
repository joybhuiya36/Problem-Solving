class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        for(int i=0;i<k;i++)
        sum+=nums[i];
        double avg=(1.0*sum)/k;
        int ptr=0;
        for(int i=k;i<n;i++)
        {
            sum-=nums[ptr++];
            sum+=nums[i];
            avg=max(avg,(1.0*sum)/k);
        }
        return avg;
    }
};
