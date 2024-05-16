class Solution {
public:
int n;
int dp[50001];
	int binary(int l, int t, vector<vector<int>> &v)
    {
        int r=n-1,mid,nxt=n;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(v[mid][0]>=t)
            {
                nxt=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nxt;
    }
	int func(int idx, vector<vector<int>> &v)
    {
        if(idx==n)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int nxt=binary(idx+1,v[idx][1],v);
        int taken=v[idx][2]+func(nxt,v);
        int not_taken=func(idx+1,v);
        return dp[idx]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        vector<vector<int>> v(n, vector<int>(3));
        for(int i=0;i<n;i++)
        {
            v[i][0]=startTime[i];
            v[i][1]=endTime[i];
            v[i][2]=profit[i];
        }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return func(0,v);
    }
};
