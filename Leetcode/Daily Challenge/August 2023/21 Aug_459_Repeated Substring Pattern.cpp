class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=n/2;i>=1;i--)
        {
            if(n%i==0)
            {
                if(s.substr(0,n-i)==s.substr(i))
                return true;
            }
        }
        return false;
    }
};
//or
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        for(int i=1;i<s.length();i++)
        {
            int j=i, k=0;
            while(s[k]==str[j])
            {
                j++; k++;
                if(k==s.length())
                return true;
            }
            
        }
        return false;
    }
};
