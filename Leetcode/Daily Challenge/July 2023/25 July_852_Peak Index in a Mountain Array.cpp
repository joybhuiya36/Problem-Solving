class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1,mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if((mid-1>=0 && arr[mid]>arr[mid-1]) && arr[mid]>arr[mid+1])
            return mid;
            else if(arr[mid+1]>arr[mid])
            l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};
//or

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        
        while(start<end)
        {
           int mid=start+(end-start)/2;
           if(arr[mid]<arr[mid+1])
            {
                start=mid+1;
            }
            if(arr[mid]>arr[mid+1])
            {
                end=mid;
            }
        }
        return start;	//or  return end;
        
    }
};
