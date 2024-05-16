//DP
//Memorization
class Solution {
public:
int num;
    int func(int idx, string &s, vector<int> &dp)
    {
        if(idx>s.length())
        return 0;
        if(idx==s.length())
        return 1;
        if(dp[idx]!=-1)
        return dp[idx];
        if(s[idx]=='0')
        return 0;
        int count=0;
        count+=func(idx+1,s,dp);
        num=10*(s[idx]-'0')+(s[idx+1]-'0');
        if(num<=26)
        count+=func(idx+2,s,dp);
        return dp[idx]=count;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return func(0,s,dp);
    }
};
//Tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length(), num;
        vector<int> dp(n+1,0);
        dp[n]=1;
        dp[n-1]=s[n-1]=='0'?0:1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            continue;
            dp[i]+=dp[i+1];
            num=10*(s[i]-'0')+(s[i+1]-'0');
            if(num<=26)
            dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};
//Space Optimized
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.length(), num;
        int cur=0, next, next2=1;
        next=s[n-1]=='0'?0:1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                next2=next;
                next=0;
                continue;
            }
            cur=next;
            num=10*(s[i]-'0')+(s[i+1]-'0');
            if(num<=26)
            cur+=next2;
            next2=next;
            next=cur;
        }
        return next;
    }
};
