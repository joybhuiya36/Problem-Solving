class Solution {
public:
int dp[2001][2001];
    int isExist(int k, int num, vector<int> &stn, int &n)
    {
        for(int i=k;i<n;i++)
        {
            if(stn[i]==num)
            return i;
            else if(stn[i]>num)
            return 0;
        }
        return 0;
    }
	bool check(int i, int k, vector<int> &stn, int &n)
    {
        if(i==n-1)
        return true;
        if(i>=n)
        return false;
        if(dp[i][k]!=-1)
        return dp[i][k];
        bool rslt=false;
        if(int j=isExist(i+1,stn[i]+k-1,stn,n))
        {
            rslt=check(j,k-1,stn,n);
        }
        if(rslt) return dp[i][k]=true;
        if(int j=isExist(i+1,stn[i]+k,stn,n))
        {
            rslt=check(j,k,stn,n);
        }
        if(rslt) return dp[i][k]=true;
        if(int j=isExist(i+1,stn[i]+k+1,stn,n))
        {
            rslt=check(j,k+1,stn,n);
        }
        return dp[i][k]=rslt;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
        return false;
        int n=stones.size();
        memset(dp,-1,sizeof(dp));
        return check(1,1,stones,n);
    }
};
