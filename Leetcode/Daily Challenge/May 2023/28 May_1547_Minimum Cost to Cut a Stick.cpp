class Solution {
public:
int dp[103][103];
    int cut(int i, int j, vector<int> &cuts)
    {
        if(j-i==1)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        ans=min(ans,cut(i,k,cuts)+cut(k,j,cuts));
        return dp[i][j]=ans+(cuts[j]-cuts[i]);
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int l=cuts.size();
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return cut(0,l-1,cuts);
    }
};
