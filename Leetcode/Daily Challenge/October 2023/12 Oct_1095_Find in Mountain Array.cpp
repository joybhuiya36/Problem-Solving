class Solution {
public:
    int peakFinder(MountainArray &arr, int l, int r)
    {
        int mid;
        while(l<r)
        {
            mid=l+((r-l)/2);
            if(arr.get(mid)<arr.get(mid+1))
            l=mid+1;
            else r=mid;
        }
        return l;
    }
    int binarySearch(int l, int r, MountainArray &arr, int t)
    {
        int mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(arr.get(mid)==t)
            return mid;
            else if(arr.get(mid)>t)
            r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int reverseBinarySearch(int l, int r, MountainArray &arr, int t)
    {
        int mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(arr.get(mid)==t)
            return mid;
            else if(arr.get(mid)>t)
            l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int r=mountainArr.length()-1;
        int l=0, mid;
        int idx=peakFinder(mountainArr, 0, r);
        int ans=binarySearch(0,idx,mountainArr,target);
        if(ans!=-1) return ans;
        ans=reverseBinarySearch(idx,r,mountainArr,target);
        return ans;
    }
};
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

