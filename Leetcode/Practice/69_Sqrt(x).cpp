//Binary Search
class Solution {
public:
typedef unsigned int ui;
    int mySqrt(int x) {
        ui l=0,r=55555,mid,n=(ui)x;
        int ans;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(mid*mid<=n)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
//Linear Search
class Solution {
public:
typedef long long ll;
    int mySqrt(int x) {
        ll n=(ll)x;
        for(ll i=0;i<=n+1;i++)
        {
            if(i*i>x)
            return i-1;
        }
        return 0;
    }
};
