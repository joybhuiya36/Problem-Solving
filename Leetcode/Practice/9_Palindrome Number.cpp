class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long a,b=0;
        a=x;
        while(x)
        {
            b=b*10+(x%10);
            x/=10;
        }
        if(a==b) return true;
        return false;
    }
};
