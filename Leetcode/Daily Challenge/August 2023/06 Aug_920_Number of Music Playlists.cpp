class Solution {
public:
typedef long long ll;
int dp[101][101];
const int mod=1e9+7;
	ll playlist(int songs, int uniq, int &n, int &g, int &k)
    {
        if(songs==g)
        {
            if(uniq==n) return dp[songs][uniq]=1;
            return 0;
        }
        if(dp[songs][uniq]!=-1) return dp[songs][uniq];
        ll rslt=0;
        if(n>uniq)
        rslt+=(n-uniq)*playlist(songs+1,uniq+1,n,g,k);
        if(uniq>k)
        rslt+=(uniq-k)*playlist(songs+1,uniq,n,g,k);
        return dp[songs][uniq]=rslt%mod;

    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return playlist(0,0,n,goal,k);
    }
};
