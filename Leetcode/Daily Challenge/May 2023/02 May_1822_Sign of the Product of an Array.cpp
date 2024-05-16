//Minus Sign Counting Approach
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            count++;
            else if(nums[i]==0)
            return 0;
        }
        if(count%2==0)
        return 1;
        else
        return -1;
    }
};
//Minus Sign Producting Approach
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            sign*=-1;
            else if(nums[i]==0)
            return 0;
        }
        return sign;
    }
};
