class Solution {
public:
    int minOperations(vector<int>& nums) {
        int arr[1000001]={0};
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }
        int c=0;
        for(int i=1;i<1000001;i++)
        {
            if(arr[i]==0)
            continue;
            if(arr[i]==1)
            return -1;
            if(arr[i]%3==0)
            c+=arr[i]/3;
            else if((arr[i]-1)%3==0)
            c+=(arr[i]-4)/3+2;
            else
            c+=(arr[i]/3)+1;
        }
        return c;
    }
};
