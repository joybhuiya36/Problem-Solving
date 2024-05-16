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
