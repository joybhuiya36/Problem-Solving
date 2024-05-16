class Solution {
public:
int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

    void change(int &l, int &mid, int r, vector<vector<int>> &cells, vector<vector<int>> &grid, int sign)
    {
        if(sign==1)
        {
            for(int i=l;i<=mid;i++)
            {
                grid[cells[i][0]-1][cells[i][1]-1]=1;
            }
        }
        else
        {
            for(int i=r;i>mid;i--)
            {
                grid[cells[i][0]-1][cells[i][1]-1]=0;
            }
        }
    }
    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visit, int &r, int &c)
    {
        if(grid[i][j]==0 && visit[i][j]==0)
        {
            if(i==r-1)
            return 1;
            visit[i][j]=1;
            bool check=0;
            if(i+1<r) check=dfs(i+1,j,grid,visit,r,c);
            if(check) return check;
            if(j+1<c) check=dfs(i,j+1,grid,visit,r,c);
            if(check) return check;
            if(i-1>=0) check=dfs(i-1,j,grid,visit,r,c);
            if(check) return check;
            if(j-1>=0) check=dfs(i,j-1,grid,visit,r,c);
            if(check) return check;
            return check;
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col,0));
        int l=0,r=cells.size()-1,mid=l+((r-l)/2),ans=-1;
        change(l,mid,r,cells,grid,1);
        while(l<=r)
        {
            bool check=false;
            vector<vector<int>> visit(row,vector<int>(col,0));
            for(int i=0;i<col;i++)
            {
                if(grid[0][i]==0)
                {
                    check=dfs(0,i,grid,visit,row,col);
                    if(check)
                    {
                        ans=mid+1;
                        break;
                    }
                }
            }
            if(check)
            {
                l=mid+1;
                mid=l+((r-l)/2);
                if(mid>=0)
                change(l,mid,r,cells,grid,1);
            }
            else
            {
                r=mid-1;
                mid=l+((r-l)/2);
                if(mid>=0)
                change(l,mid,r+1,cells,grid,-1);
            }
        }
        return ans;
    }
};
