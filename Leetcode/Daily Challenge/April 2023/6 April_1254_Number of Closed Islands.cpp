class Solution {
public:
int m,n;
bool checker;
vector<vector<int>> visit;
	void dfs(int row, int col, vector<vector<int>> &grid)
    {
        if(row>=0 && col>=0 && row<m && col<n && visit[row][col]==0 && grid[row][col]==0)
        {
            visit[row][col]=1;
            if(row==0 || col==0 || row==m-1 || col==n-1)
            checker= false;
            dfs(row,col+1,grid);
            dfs(row,col-1,grid);
            dfs(row+1,col,grid);
            dfs(row-1,col,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size(); n=grid[0].size();
        int count=0;
        visit.resize(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                checker=true;
                if(grid[i][j]==0 and visit[i][j]==0)
                {
                    dfs(i,j,grid);
                    if(checker)
                    count++;
                }
            }
        }
        return count;
    }
};
