//DP
//Memorization
class Solution {
public:
    int pairs(int idx, bool takeit, vector<int> &val, vector<vector<int>> &dp, int &n)
    {
        if(idx==n)
        return INT_MIN;
        if(dp[idx][takeit]!=-1)
        return dp[idx][takeit];
        if(takeit==false)
        return dp[idx][takeit]= max(val[idx]+idx+pairs(idx+1,true,val,dp,n),pairs(idx+1,false,val,dp,n));
        else
        return dp[idx][takeit]= max(val[idx]-idx,pairs(idx+1,true,val,dp,n));
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return pairs(0,false,values,dp,n);
    }
};
//One Pass
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int l=val[0], r=val[1]-1, mx=l+r, idx=0, idx2=1;
        for(int i=2;i<val.size();i++)
        {
            if(val[i-1]+i-1>l)
            {
                l=val[i-1]+i-1;
                idx=i-1;
            }
            if(val[i]-i>r || idx>=idx2)
            {
                r=val[i]-i;
                idx2=i;
            }
            if(idx2>idx)
            mx=max(mx,l+r);
        }
        return mx;
    }
};
//or
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int l=val[0], r, mx=0;
        for(int i=1;i<val.size();i++)
        {
            r=val[i]-i;
            mx=max(mx,l+r);
            l=max(l,val[i]+i);
        }
        return mx;
    }
};
