class Solution {
public:
    int subarraySum(int *nums, int &k, int &n)
    {
        int sum=0,count=0;
        unordered_map<int,int> mp;
        mp[sum]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.count(sum-k))
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count++;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m=mat.size(), n=mat[0].size();
        int sum[n];
        int count=0;
        for(int i=0;i<m;i++)
        {
            memset(sum,0,sizeof(sum));
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    sum[k]+=mat[j][k];
                }
                count+=subarraySum(sum,target,n);
            }
        }
        return count;
    }
};
