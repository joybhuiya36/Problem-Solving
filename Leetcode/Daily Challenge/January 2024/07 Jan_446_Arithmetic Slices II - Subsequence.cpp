class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long,int> mp[n];
        int ans=0;
        long diff;
        int count_j;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                diff=(long)nums[i]-nums[j];
                count_j=0;
                if(mp[j].count(diff))
                {
                    count_j=mp[j][diff];
                }
                mp[i][diff]+=count_j+1;
                ans+=count_j;
            }
        }
        return ans;
    }
};
