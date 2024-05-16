class Solution {
public:
unordered_set<string> mp;
    bool func(int idx, string &s, vector<int> &dp)
    {
        if(idx==s.length())
        return true;
        if(dp[idx]!=-1)
        return dp[idx];
        for(int i=idx+1;i<=s.length();i++)
        {
            if(mp.count(s.substr(idx,i-idx)) && func(i,s,dp))
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
