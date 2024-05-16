typedef long long ll;
class Solution {
public:
vector<vector<ll>> pas;
ll mod=1e9+7;
    ll solve(vector<int> &nums)
    {
        int n=nums.size();
        if(n<3)
        return 1;
        vector<int> left, right;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])
            left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll x=solve(left);
        ll y=solve(right);
        ll z=pas[n-1][left.size()];
        return (((x*y)%mod)*z)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pas.resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                pas[i].push_back(1);
                else pas[i].push_back((pas[i-1][j-1]+pas[i-1][j])%mod);
            }
        }
        return solve(nums)-1;
    }
};
