class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        long long m=n;
        return !(m&(m-1));			//n=2^x (x is an integer)
    }
};
//Or
class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n<=0)
       return false;
       if(n==1)
       return true;
       return isPowerOfTwo(n/2) && n%2==0;
    }
};
