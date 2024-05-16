class Solution {
public:
int l,d,r,c;
int dir[8][2]={
    {-1,-1}, {-1,0}, {-1,1},
    {0,-1},          {0,1},
    {1,-1},  {1,0},  {1,1}
};
    int check(int i, int j, vector<vector<int>> &board, int &m, int &n)
    {
        l=0;d=0;
        for(int k=0;k<8;k++)
        {
            r=i+dir[k][0]; c=j+dir[k][1];
            if(r<0 || r>=m || c<0 || c>=n)
            continue;
            if(board[r][c]==1)
            l++;
            else d++;
        }
        if(board[i][j]==1)
        {
            if(l<2 || l>3)
            return 0;
            else
            return 1;
        }
        else
        {
            if(l==3)
            return 1;
        }
        return 0;

    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> b=board;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i][j]=check(i,j,b,m,n);
            }
        }
    }
};
