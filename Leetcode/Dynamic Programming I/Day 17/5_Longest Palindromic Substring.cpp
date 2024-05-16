//DP (Python)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        dp=[[False]*n for _ in range(n)]
        l=0
        idx=0
        for g in range(n): #g -> gap
            i=0 #row
            for j in range(g,n,1): #j -> col
                if g==0:
                    dp[i][j]=True
                elif g==1:
                    if s[i]==s[j]:
                        dp[i][j]=True
                    else: dp[i][j]=False
                else:
                    if s[i]==s[j] and dp[i+1][j-1]==True:
                        dp[i][j]=True
                if dp[i][j]==True:
                    l=g+1
                    idx=i
                i+=1
        return s[idx:idx+l]
//Expand from center (C++)
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
