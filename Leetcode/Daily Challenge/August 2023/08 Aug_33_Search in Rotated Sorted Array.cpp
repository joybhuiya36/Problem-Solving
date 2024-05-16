class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, mid, r=nums.size()-1;
        while(l<=r)
        {
            mid=((r-l)/2)+l;
            if(nums[mid]==target)
            return mid;
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<nums[mid])
                r=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]<=nums[r])
            {
                if(nums[mid]<target && target<=nums[r])
                l=mid+1;
                else r=mid-1;

            }
        }
        return -1;
    }
};
//or
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, mid, r=nums.size()-1;
        while(l<=r)
        {
            mid=((r-l)/2)+l;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            {
                if(nums[l]<=nums[mid] && nums[l]<=target)
                r=mid-1;
                else if(nums[mid]<=nums[r])
                r=mid-1;
                else
                l=mid+1;
            }
            else if(nums[mid]<target)
            {
                if(nums[mid]<=nums[r] && target<=nums[r])
                l=mid+1;
                else if(nums[l]<=nums[mid])
                l=mid+1;
                else
                r=mid-1;
            }
        }
        return -1;
    }
};
