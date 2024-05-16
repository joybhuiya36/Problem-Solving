class Solution {
public:
int m,n,count;
vector<vector<int>> visit;
bool checker;
    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        if(row>=0 && col>=0 && row<m && col<n && visit[row][col]==0 && grid[row][col]==1)
        {
            visit[row][col]=1;
            count++;
            if(row==0 || col==0 || row==m-1 || col==n-1)
            checker=false;
            dfs(row,col+1,grid);
            dfs(row,col-1,grid);
            dfs(row+1,col,grid);
            dfs(row-1,col,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int total=0;
        m=grid.size(); n=grid[0].size();
        visit.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visit[i][j]==0)
                {
                    count=0;
                    checker=true;
                    dfs(i,j,grid);
                    if(checker)
                    total+=count;
                }
            }
        }
        return total;
    }
};
