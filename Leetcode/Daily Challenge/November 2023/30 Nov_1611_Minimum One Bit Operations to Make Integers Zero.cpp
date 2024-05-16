class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        vector<int> f(31);
        f[0]=1;
        for(int i=1;i<31;i++)
        f[i]=2*f[i-1]+1;
        int ans=0, sign=1, bit;
        for(int i=30;i>=0;i--)
        {
            bit=((1<<i)&n);
            if(bit==0) continue;
            if(sign>0)
            ans+=f[i];
            else ans-=f[i];
            sign*=-1;
        }
        return ans;
    }
};
