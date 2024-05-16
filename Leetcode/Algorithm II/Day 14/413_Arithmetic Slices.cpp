//Short Solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0, count=0, n=nums.size();
        for(int i=2;i<n;i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]) count++, ans+=count;
            else count=0;
        }
        return ans;
    }
};
//My Solution
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
