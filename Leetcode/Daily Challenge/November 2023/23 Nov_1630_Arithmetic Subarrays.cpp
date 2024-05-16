class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(), m=l.size();
        vector<bool> bl;
        for(int i=0;i<m;i++)
        {
            int n=r[i]-l[i]+1;
            if(n==2)
            {
                bl.push_back(true);
                continue;
            }
            int temp[n];
            for(int j=l[i],k=0; j<=r[i]; j++,k++)
            temp[k]=nums[j];
            sort(temp,temp+n);
            int j=0;
            for(;j<n-2;j++)
            {
                if(temp[j+1]-temp[j]!=temp[j+2]-temp[j+1])
                {
                    bl.push_back(false);
                    break;
                }
            }
            if(j==n-2) bl.push_back(true);
        }
        return bl;
    }
};
