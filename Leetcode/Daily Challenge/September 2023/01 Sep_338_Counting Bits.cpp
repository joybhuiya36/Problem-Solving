class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> b(n+1);
        b[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            b[i]=b[i/2];
            else b[i]=b[i/2]+1;
        }
        return b;
    }
};
