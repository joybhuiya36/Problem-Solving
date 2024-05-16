//DP
//Memorization
class Solution {
public:
    int pascal(int i, int j, vector<vector<int>> &dp)
    {
        if(dp[i].size()==j)
        dp[i].push_back(0);
        else
        return dp[i][j];
        if(j==0 || i==j)
        return dp[i][j]=1;
        return dp[i][j]=pascal(i-1,j-1,dp)+pascal(i-1,j,dp);
    }
    vector<int> getRow(int n) {
        n++;
        vector<vector<int>> dp(n);
        dp[0].push_back(1);
        for(int i=0;i<n;i++)
        pascal(n-1,i,dp);
        return dp[n-1];
    }
};
//Tabulation
class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                v[i].push_back(1);
                else
                v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            }
        }
        return v[n-1];
    }
};
//Space Optimization
class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int> pre(n),cur(n);
        pre[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                cur[j]=1;
                else
                cur[j]=pre[j]+pre[j-1];
            }
            pre=cur;
        }
        return pre;
    }
};
//My first Submission
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        v[0]=1;
        int n;
        for(int i=1;i<=rowIndex;i++)
        {
            n=i/2;
            while(n)
            {
                v[n]=v[n]+v[n-1];
                n--;
            }
            if(i%2==1)
            v[(i/2)+1]=v[i/2];
        }
        int i=(rowIndex/2)+1;
        int j;
        if(rowIndex%2==1)
        j=rowIndex/2;
        else
        j=(rowIndex/2)-1;
        while(i<=rowIndex)
        v[i++]=v[j--];
        return v;
    }
};
