//Total 4 Approach Given
//Memorization
class Solution {
public:
vector<vector<int>> dp;
    int func(int row, int col, vector<vector<int>>& tri)
    {
        if(row==tri.size())
        return 0;
        if(dp[row][col]!=INT_MAX)
        return dp[row][col];
        return dp[row][col]=tri[row][col]+min(func(row+1,col,tri),func(row+1,col+1,tri));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<triangle.size();i++)
        {
            dp.push_back({});
            for(int j=0;j<triangle[i].size();j++)
            dp[i].push_back(INT_MAX);
        }
        return func(0,0,triangle);
    }
};
//Tabulation
int TABULATION(vector<vector<int> > &triangle,int n,vector<vector<int> > &dp)
    {    
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {    
                int down = triangle[i][j]+dp[i+1][j];
                int diagonal = triangle[i][j]+dp[i+1][j+1];    
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
//Space Optimized
int SO(vector<vector<int> > &triangle,int n)
    {   vector<int>cur(n,-1),next(n,-1);
        for(int j=0;j<n;j++){
            next[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {    
                int down = triangle[i][j]+next[j];
                int diagonal = triangle[i][j]+next[j+1];    
                cur[j] = min(down, diagonal);
            }
            next=cur;
        }
        return next[0];
    }
//Highly Optimized
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int m=triangle.size();
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                triangle[i][j]+=min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

