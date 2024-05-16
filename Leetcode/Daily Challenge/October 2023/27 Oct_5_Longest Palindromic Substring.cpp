class Solution {
public:
int n;
    int func(int l, int r, string &s)
    {
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        n=s.length();
        if(n==1)
        return s;
        int op1,op2,len,start=0,max_len=1;
        for(int i=0;i<n;i++)
        {
            op1=func(i,i,s);
            op2=func(i,i+1,s);
            len=max(op1,op2);
            if(len>max_len)
            {
                start=i-((len-1)/2);
                max_len=len;
            }
        }
        return s.substr(start,max_len);
    }
};
