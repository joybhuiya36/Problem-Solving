class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0,bit;
        while(a || b || c)
        {
            bit=c&1;
            if(bit==0)
            {
                if((a&1)==1) count++;
                if((b&1)==1) count++;
            }
            else if(bit==1)
            {
                if((a&1)==0 && (b&1)==0)
                count++;
            }
            a>>=1; b>>=1; c>>=1;
        }
        return count;
    }
};
