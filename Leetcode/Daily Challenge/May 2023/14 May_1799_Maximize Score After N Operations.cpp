class Solution {
public:
vector<int> v;
priority_queue<pair<int,vector<int>>> pq;
int mx=0;
vector<bool> visit;
vector<vector<int>> dp;
    void pair(int idx, int sum, int count, vector<int> &nums, int &n)
    {
        visit[idx]=true;
        for(int i=idx+1;i<n;i++)
        {
            if(visit[i]==true) continue;
            visit[i]=true;
            if(dp[idx][i]==-1)
            dp[idx][i]=gcd(nums[idx],nums[i]);
            v.push_back(dp[idx][i]);
            sum+=dp[idx][i];
            if(count+1==n/2)
            {
                if(sum>mx)
                {
                    mx=sum;
                    while(pq.size()>0)
                    pq.pop();
                    pq.push({mx,v});
                }
                else if(sum==mx)
                {
                    mx=sum;
                    pq.push({mx,v});
                }
            }
            else
            for(int j=idx+1;j<n;j++)
            {
                if(visit[j]==false)
                pair(j,sum,count+1,nums,n);
            }
            v.pop_back();
            visit[i]=false;
            sum-=dp[idx][i];
        }
        visit[idx]=false;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size(),ans=0;
        visit.resize(n,false);
        dp.resize(n,vector<int>(n,-1));
        pair(0,0,0,nums,n);
        n/=2;
        while(pq.size()>0)
        {
            mx=0;
            v=pq.top().second;
            sort(v.begin(),v.end());
            for(int i=n;i>0;i--)
            mx+=v[i-1]*i;
            ans=max(mx,ans);
            pq.pop();
        }
        return ans;
    }
};
