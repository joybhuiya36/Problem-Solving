// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n,mid=n;
        while(l<r)
        {
            mid=((r-l)/2)+l;
            if(!isBadVersion(mid))
            l=mid+1;
            else
            r=mid;
        }
        return r;
    }
};
