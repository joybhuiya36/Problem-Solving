//DP Tabulation
class Solution {
public:
    int nthUglyNumber(int n) {
        int p=0, q=0, r=0;
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(2*dp[p],min(3*dp[q],5*dp[r]));
            if(dp[i]==2*dp[p]) p++;
            if(dp[i]==3*dp[q]) q++;
            if(dp[i]==5*dp[r]) r++;
        }
        return dp[n-1];
    }
};
//TLE
class Solution {
public:
    int nthUglyNumber(int n) {
        int i=2;
        vector<int> arr(9999999,0);
        for(int j=1;j<n;i++)
        {
            int a=i;
            if(a%2==0)
            {
                a/=2;
            }
            else if(a%3==0)
            {
                a/=3;
            }
            else if(a%5==0)
            {
                a/=5;
            }
            else
            {
                arr[i]=1;
            }
            if(arr[a]==1)
            {
                arr[i]=1;
            }
            else if(arr[a]==0)
            j++;
            cout<<i<<" "<<j<<endl;
        }
        return i-1;
    }
};
