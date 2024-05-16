class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int l=0,r=n-1;
        char c1,c2;
        while(l<=r)
        {
            c1=s[l]; c2=s[r];
            if(!isalpha(c1) && !isdigit(c1))
            {
                l++; continue;
            }
            if(!isalpha(c2) && !isdigit(c2))
            {
                r--; continue;
            }
            if(isalpha(c1) && isupper(c1)) c1+=32;
            if(isalpha(c2) && isupper(c2)) c2+=32;
            if(c1==c2)
            {
                l++; r--;
            }
            else
            return false;
        }
        return true;
    }
};
