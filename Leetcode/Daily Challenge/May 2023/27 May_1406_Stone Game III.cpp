//DP
//Memorization
class Solution {
public:
    int game(int i, int alice, vector<int> &val, vector<vector<int>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i][alice]!=-1)
        return dp[i][alice];
        int total=0, ans= alice==1? INT_MIN:INT_MAX;
        for(int j=i;j<i+3;j++)
        {
            if(j==n) break;
            total+=val[j];
            if(alice==1)
            {
                ans=max(ans, total+game(j+1,!alice,val,dp,n));
            }
            else
            {
                ans=min(ans,game(j+1,!alice,val,dp,n));
            }
        }
        
        return dp[i][alice]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size(),sum=0;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        for(int &i:stoneValue)
        sum+=i;
        int ans=game(0,1,stoneValue,dp,n);
        sum-=ans;
        if(ans>sum)
        return "Alice";
        else if(ans<sum)
        return "Bob";
        else return "Tie";
    }
};
//or
class Solution {
public:
    int game(int i, vector<int> &val, vector<int> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int total=val[i]-game(i+1,val,dp,n);
        if(i+1<n)
        total=max(total,val[i]+val[i+1]-game(i+2,val,dp,n));
        if(i+2<n)
        total=max(total,val[i]+val[i+1]+val[i+2]-game(i+3,val,dp,n));
        return dp[i]=total;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1);
        int ans=game(0,stoneValue,dp,n);
        if(ans>0)
        return "Alice";
        else if(ans<0)
        return "Bob";
        else return "Tie";
    }
};
//Tabulation
class Solution {
public:
    string stoneGameIII(vector<int>& val) {
        int n=val.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=val[i]-dp[i+1];
            if(i+2<=n)
            dp[i]=max(dp[i],val[i]+val[i+1]-dp[i+2]);
            if(i+3<=n)
            dp[i]=max(dp[i],val[i]+val[i+1]+val[i+2]-dp[i+3]);
        }
        int ans=dp[0];
        if(ans>0)
        return "Alice";
        else if(ans<0)
        return "Bob";
        else return "Tie";
    }
};
//Space Optimization
class Solution {
public:
    string stoneGameIII(vector<int>& val) {
        int n=val.size();
        int ans=0,a=0,b=0,c=0;
        for(int i=n-1;i>=0;i--)
        {
            ans=val[i]-a;
            if(i+2<=n)
            ans=max(ans,val[i]+val[i+1]-b);
            if(i+3<=n)
            ans=max(ans,val[i]+val[i+1]+val[i+2]-c);
            c=b; b=a; a=ans;
        }
        if(ans>0)
        return "Alice";
        else if(ans<0)
        return "Bob";
        else return "Tie";
    }
};
