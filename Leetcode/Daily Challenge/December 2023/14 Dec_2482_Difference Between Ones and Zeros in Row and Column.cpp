class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ro[m], rz[m], co[n], cz[n];
        for(int i=0;i<m;i++)
        {
            ro[i]=0; rz[i]=0;
        }
        for(int j=0;j<n;j++)
        {
            co[j]=0; cz[j]=0;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ro[i]++; co[j]++;
                }
                else
                {
                    rz[i]++; cz[j]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=ro[i]+co[j]-rz[i]-cz[j];
            }
        }
        return grid;
    }
};
