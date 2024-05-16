class Solution {
public:
int m,n;
int dp[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2)
    {
        if(i==m || j==n)
        return -1e9;
        if(dp[i][j]!=-1e9)
        return dp[i][j];
        int val=nums1[i]*nums2[j];
        int take_i_j=val+solve(i+1,j+1,nums1,nums2);
        int take_i=solve(i+1,j,nums1,nums2);
        int take_j=solve(i,j+1,nums1,nums2);
        
        return dp[i][j]=max(take_i_j,max(take_i,max(take_j,val)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m= nums1.size(), n= nums2.size();
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++)
            dp[i][j]=-1e9;
        }
        return solve(0,0,nums1,nums2);
    }
};
