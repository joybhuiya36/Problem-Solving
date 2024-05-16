class Solution {
public:
int mod=1e9+7;
    int countOrders(int n) {
        if(n==1) return 1;
        long long rslt=1;
        int space, psb;
        for(int i=2;i<=n;i++)
        {
            space=(i-1)*2+1;
            psb=space*(space+1)/2;
            rslt*=psb;
            rslt%=mod;
        }
        return rslt;
    }
};
