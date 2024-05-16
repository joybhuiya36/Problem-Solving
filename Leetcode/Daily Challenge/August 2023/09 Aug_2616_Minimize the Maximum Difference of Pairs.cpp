class Solution {
public:
int cnt,i,n;
    bool valid(int &mid, vector<int> &nums, int &p)
    {
        cnt=0;
        i=0;
        while(i+1<n)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                cnt++; i+=2;
            }
            else i++;
            if(cnt==p) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums[0],mid,ans=0;
        n=nums.size();
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(valid(mid,nums,p))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
