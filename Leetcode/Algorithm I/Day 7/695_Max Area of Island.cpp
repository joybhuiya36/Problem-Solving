class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, int &mx)
    {
        if(grid[i][j]==1 && visited[i][j]==0)
        {
            visited[i][j]=1;
            mx++;
            if(j>0) dfs(grid,i,j-1,visited,mx);
            if(j<grid[0].size()-1) dfs(grid,i,j+1,visited,mx);
            if(i>0) dfs(grid,i-1,j,visited,mx);
            if(i<grid.size()-1) dfs(grid,i+1,j,visited,mx);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n1=grid.size(),n2=grid[0].size(),f_mx=0,mx=0;
        vector<vector<int>>visited(n1,vector<int>(n2,0));
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    mx=0;
                    dfs(grid,i,j,visited,mx);
                    f_mx=max(f_mx,mx);
                }
            }
        }
        return f_mx;
    }
};
