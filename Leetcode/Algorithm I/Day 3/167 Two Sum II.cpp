//Two Pointer Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int l=0,r=n.size()-1;
        
        while(l<r)
        {
            if(n[l]+n[r]==target)
            return {l+1,r+1};
            else if(n[l]+n[r]>target)
            r--;
            else l++;
        }
        return {};
    }
};
//Binary Search Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int res,l,r,mid;
        for(int i=0;i<n.size()-1;i++)
        {
            res=target-n[i];
            l=i+1;
            r=n.size()-1;
            while(l<=r)
            {
                mid=((r-l)/2)+l;
                if(n[mid]==res)
                return {i+1,mid+1};
                else if(n[mid]<res)
                l=mid+1;
                else r=mid-1;
            }
        }
        return {};
    }
};
