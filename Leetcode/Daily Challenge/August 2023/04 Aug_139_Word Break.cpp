//DP
//Memorization
class Solution {
public:
unordered_set<string> mp;
    bool func(int idx, string &s, vector<int> &dp)
    {
        if(idx==s.length())
        return true;
        if(dp[idx]!=-1)
        return dp[idx];
        string str;
        for(int i=idx;i<s.length();i++)
        {
            str+=s[i];
            if(mp.count(str) && func(i+1,s,dp))
            return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(),-1);
        for(int i=0;i<wordDict.size();i++)
        mp.insert(wordDict[i]);
        return func(0,s,dp);
    }
};
//Iterative
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        string str;
        bool dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            str="";
            for(int j=i;j<n;j++)
            {
                str+=s[j];
                if(mp.count(str) && dp[j+1])
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};
