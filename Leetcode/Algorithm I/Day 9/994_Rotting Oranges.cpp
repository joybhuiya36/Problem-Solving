class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                fresh++;
            }
        }
        if(fresh==0)
        return 0;
        else if(q.size()==0)
        return -1;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int> cur;
        int row, col, t, day=0;
        while(!q.empty())
        {
            t=q.size();
            while(t--)
            {
                cur=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    row=cur.first+dir[i][0];
                    col=cur.second+dir[i][1];
                    if(row>=0 && row<m && col>=0 && col<n)
                    {
                        if(grid[row][col]==1)
                        {
                            grid[row][col]=2;
                            fresh--;
                            q.push({row,col});
                        }
                    }
                    if(fresh<=0) return day+1;
                }
            }
            day++;
        }
        if(fresh>0) return -1;
        return day;
    }
};
