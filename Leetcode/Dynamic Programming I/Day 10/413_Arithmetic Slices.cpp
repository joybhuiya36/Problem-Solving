//Total 3 Approaches
//DP Tabuation
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0;
        vector<int> dp(n,0);
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            dp[i]=1+dp[i-1];
            ans+=dp[i];
        }
        return ans;
    }
};
//Space Optimized
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0, cur=0, pre=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                cur=1+pre;
                ans+=cur;
                pre=cur;
            }
            else
            {
                cur=0;
                pre=0;
            }
        }
        return ans;
    }
};
//My Approach
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
        return 0;
        int count=2, ans=0;
        int diff=nums[1]-nums[0];
        for(int i=2;i<nums.size();i++)
        {
            if(diff==nums[i]-nums[i-1])
            count++;
            else
            {
                if(count>2)
                {
                    if(count==3)
                    ans+=1;
                    else
                    {
                        count-=2;
                        ans+=(count*(count+1))/2;
                    }
                }
                diff=nums[i]-nums[i-1];
                count=2;
            }
        }
        if(count>2)
        {
            if(count==3)
            ans+=1;
            else
            {
                count-=2;
                ans+=(count*(count+1))/2;
            }
        }
        return ans;
    }
};
