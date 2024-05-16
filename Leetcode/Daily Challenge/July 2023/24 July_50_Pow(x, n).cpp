class Solution {
public:
    double bx(double x, long long n)
    {
        if(n==0) return 1.0;
        double y=bx(x,n/2);
        if(n%2==0)
        return y*y;
        else return y*y*x;
    }
    double myPow(double x, int n) {
        if(n>0)
        return bx(x,n);
        else return 1.0/bx(x,((long long)n*-1));
    }
};

//or
class Solution {
public:
    double pw(double x, long n)
    {
        if(n==0) return 1.0;
        if(n%2==0)
        return pw(x*x,n/2);
        else return x*pw(x*x,n/2);
    }
    double myPow(double x, int n) {
        if(n>0)
        return pw(x,n);
        else
        return pw(1/x,long(n)*-1);
    }
};
