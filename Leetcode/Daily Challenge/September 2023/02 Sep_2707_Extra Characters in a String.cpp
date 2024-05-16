class Solution {
public:
unordered_set<string> mp;
	int finder(int idx, string &s, int dp[], int &n)
    {
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        string curS="";
        int curExtra,restExtra,totalExtra=n;
        for(int i=idx;i<n;i++)
        {
            curExtra=0;
            curS+=s[i];
            if(!mp.count(curS))
            {
                curExtra=i-idx+1;
            }
            restExtra=finder(i+1,s,dp,n);
            totalExtra=min(totalExtra,curExtra+restExtra);
        }
        return dp[idx]=totalExtra;
    }
    int minExtraChar(string s, vector<string>& dic) {
        int n=s.length();
        for(int i=0;i<dic.size();i++)
        mp.insert(dic[i]);
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return finder(0,s,dp,n);
    }
};
