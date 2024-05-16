class Solution {
public:
int fst=-1, lst=-1, mid;
    void leftBinary(int l, int r, vector<int> &nums, int t)
    {
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(nums[mid]>=t)
            {
                if(nums[mid]==t)
                fst=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
    }
    void rightBinary(int l, int r, vector<int> &nums, int t)
    {
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(nums[mid]<=t)
            {
                if(nums[mid]==t)
                lst=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        leftBinary(0,nums.size()-1,nums,target);
        rightBinary(0,nums.size()-1,nums,target);
        return {fst,lst};
    }
};
