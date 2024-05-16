class Solution {
public:
	int lower(int l, int r, vector<int> &n, int &t)
    {
        while(l<=r)
        {
            int mid=((r-l)/2)+l;
            if(n[mid]>=t)
            r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int upper(int l, int r, vector<int> &n, int &t)
    {
        while(l<=r)
        {
            int mid=((r-l)/2)+l;
            if(n[mid]<=t)
            l=mid+1;
            else r=mid-1;
        }
        return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
        return {-1,-1};
        int start=lower(0,n-1,nums,target);
        if(start==n || nums[start]!=target)
        return {-1,-1};
        int end=upper(0,n-1,nums,target);
        return{start,end};
    }
};
