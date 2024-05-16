class Solution {
public:
int count=0,m,n;
	void dfs(int i, int j, vector<vector<int>> &visit, vector<vector<char>> &grid)
    {
        if(visit[i][j]==0 && grid[i][j]=='1')
        {
        	visit[i][j]=1;
        	if(i+1<m)
        	dfs(i+1,j,visit,grid);
        	if(i-1>=0)
        	dfs(i-1,j,visit,grid);
        	if(j+1<n)
        	dfs(i,j+1,visit,grid);
        	if(j-1>=0)
        	dfs(i,j-1,visit,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(); n=grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visit[i][j]==0)
                {
                    count++;
                    dfs(i,j,visit,grid);
                }
            }
        }
        return count;
    }
};	//We don't need visit[][], instead if we visit any point, then set the value to 0(water). That's memory optimization
