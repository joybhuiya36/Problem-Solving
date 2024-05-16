class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size(),ans=1;
        sort(pairs.begin(),pairs.end());
        int dp[n];
        for(int i=0;i<n;i++)
        dp[i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        ans=max(ans,dp[i]);
                    }
                }
            }
        }
        return ans;
    }
};
//or
class Solution {
public:
 
    int findLongestChain(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),[&](vector<int>&v1,vector<int>&v2){
            return v1[1]<v2[1];
        });
       int n=v.size();
       int last=v[0][1];
       int ans=1;
       for(int i=1;i<n;i++){
           if(v[i][0]>last){
               ans++;
               last=v[i][1];
           }
       }
       return ans;

 
    }
};
