//My Solution
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
//Other
class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int left = 0;
      int right = n-1;
      int mid= left + (right - left) / 2;
      while(left <= right){
        if(nums[mid] == target)
         return mid;
        if(nums[mid] >= nums[left]) {
          if(target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
           else left = mid + 1;
        } 
        else {
          if(target >= nums[mid] && target <= nums[right]) 
            left = mid + 1;
          else right = mid - 1;
        }
          mid = left + (right - left) / 2;
      }
      return -1;
    }
};
