//Bottom-up
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),mxLen=1,total=0;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[j]+1==dp[i])
                    {
                        cnt[i]+=cnt[j];
                    }
                }
            }
            mxLen=max(mxLen,dp[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==mxLen)
            total+=cnt[i];
        }
        return total;
    }
};
//Top_down
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 0);
        vector<int> count(n, 0);

        function<void(int)> calculateDP = [&](int i) {
            if (length[i] != 0)
                return;

            length[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    calculateDP(j);
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        };

	int maxLength = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            calculateDP(i);
            if (length[i] > maxLength)
                maxLength = length[i];
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength)
                result += count[i];
        }

        return result;
    }
};
