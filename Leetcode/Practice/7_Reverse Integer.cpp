class Solution {
public:
    int reverse(int x) {
        int a=x,b=0,pop;
        while(x)
        {
            pop=abs(x%10);
            if(b>(INT_MAX-pop)/10)
            return 0;
            b=(b*10)+pop;
            x/=10;
        }
        if(a<0)
        b*=-1;
        return b;
    }
};
