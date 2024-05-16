class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,mid,r=nums.size()-1;
        while(l<r)
        {
            mid=((r-l)/2)+l;
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1]))
            return mid;
            else if(mid>0 && nums[mid]<nums[mid-1])
            r=mid-1;
            else if(mid<nums.size()-1 && nums[mid]<nums[mid+1])
            l=mid+1;
        }
        return l;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,mid,r=nums.size()-1;
        while(l<r)
        {
            mid=((r-l)/2)+l;
            if(nums[mid]>nums[mid+1])
            r=mid;
            else l=mid+1;
        }
        return r; //or return l; (both l and r are same)
    }
};
