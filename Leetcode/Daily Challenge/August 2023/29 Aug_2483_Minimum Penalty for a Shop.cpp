class Solution {
public:
    int bestClosingTime(string cus) {
        int n=cus.size();
        int pfx[n+1];
        pfx[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(cus[i-1]=='Y')
            pfx[i]=pfx[i-1]+1;
            else pfx[i]=pfx[i-1];
        }
        if(pfx[n]==0) return 0;
        int ans,penalty=1e6,N=0;
        for(int i=0;i<=n;i++)
        {
            if(i>0 && cus[i-1]=='N')
            N++;
            if(pfx[n]-pfx[i]+N<penalty)
            {
                penalty=pfx[n]-pfx[i]+N;
                ans=i;
            }
        }
        return ans;
    }
};
