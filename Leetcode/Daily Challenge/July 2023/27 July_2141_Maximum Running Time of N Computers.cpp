class Solution {
public:
typedef long long ll;
	bool psb(vector<int> &btry, int &n, ll &mint)
    {
        ll target=n*mint;
        for(int &i:btry)
        {
            target-=min(mint,(ll)i);
            if(target<=0) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=1e9,r=0,mid,ans=0;
        for(int &i:batteries)
        {
            l=min(l,(ll)i);
            r+=i;
        }
        r/=n;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(psb(batteries,n,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
