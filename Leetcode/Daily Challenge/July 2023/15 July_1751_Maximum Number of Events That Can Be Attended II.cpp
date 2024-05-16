//DP
//Memorization with Linear Search
class Solution {
public:
vector<vector<int>> dp;
    int func(int idx, vector<vector<int>> &e, int k, int &n)
    {
        if(k==0 || idx==n) return 0;;
        if(dp[idx][k]!=-1)
        return dp[idx][k];
        //not_taken
        int not_taken=func(idx+1,e,k,n);
        //taken
        int taken=-1;
        int i=idx+1;
        while(i<n)
        {
            if(e[idx][1]<e[i][0])
            break;
            i++;
        }
        taken=e[idx][2]+func(i,e,k-1,n);
        return dp[idx][k]=max(taken,not_taken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        dp.resize(n,vector<int>(k+1,-1));
        return func(0,events,k,n);
    }
};
//Memorization with Binary Search
class Solution {
public:
vector<vector<int>> dp;
vector<int> v;
int i;
    int func(int idx, vector<vector<int>> &e, int k, int &n)
    {
        if(k==0 || idx==n) return 0;;
        if(dp[idx][k]!=-1)
        return dp[idx][k];
        //not_taken
        int not_taken=func(idx+1,e,k,n);
        //taken
        int taken=-1;
        v={e[idx][1],INT_MAX,INT_MAX};
        i=upper_bound(e.begin()+idx+1,e.end(),v)-e.begin();
        taken=e[idx][2]+func(i,e,k-1,n);
        return dp[idx][k]=max(taken,not_taken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        dp.resize(n,vector<int>(k+1,-1));
        return func(0,events,k,n);
    }
};
