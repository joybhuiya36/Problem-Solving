class Solution {
public:
int w_len, t_word,n;
int md=1000000007;
	long solve(int idx, int len, string &s, vector<vector<int>> &sum, vector<vector<int>> &dp)
    {
        if(len==n)
        return 1;
        if(idx==w_len)
        return 0;
        if(dp[idx][len]!=-1)
        return dp[idx][len];
        long op1=solve(idx+1,len,s,sum,dp)%md;
        long op2=(sum[idx][s[len]-'a']*solve(idx+1,len+1,s,sum,dp))%md;
        return dp[idx][len]=(op1+op2)%md;
    }
    int numWays(vector<string>& words, string &target) {
        n=target.length();
        w_len=words[0].length();
        t_word=words.size();
        vector<vector<int>> sum(w_len,vector<int>(26,0));
        for(int i=0;i<w_len;i++)
        {
            for(int j=0;j<t_word;j++)
            sum[i][words[j][i]-'a']++;
        }
        vector<vector<int>> dp(w_len,vector<int>(n+1,-1));
        return solve(0,0,target,sum,dp);
    }
};
