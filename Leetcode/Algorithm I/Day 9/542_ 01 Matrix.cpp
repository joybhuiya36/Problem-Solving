class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> v(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        pair<int,int> cur;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int row,col;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                row=cur.first+dir[i][0];
                col=cur.second+dir[i][1];
                if(row>=0 && row<m && col>=0 && col<n)
                {
                    if(v[row][col]>v[cur.first][cur.second]+1)
                    {
                        v[row][col]=v[cur.first][cur.second]+1;
                        q.push({row,col});
                    }
                }
            }
        }
        return v;
        
    }
};
