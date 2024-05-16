class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
        return -1;
        const int inf=1e9;
        // vector<vector<int>> visit(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,inf));
        dist[0][0]=1;
        q.push({1,make_pair(0,0)});
        int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int cur_weight,x,y;
        pair<int,int> cur_pair;
        while(!q.empty())
        {
            cur_weight=q.front().first;
            cur_pair=q.front().second;
            q.pop();
            if(cur_pair.first==n-1 && cur_pair.second==n-1)
            return cur_weight;
            // if(visit[cur_pair.first][cur_pair.second]==0)
            // {
            //     visit[cur_pair.first][cur_pair.second]=1;
                for(int i=0;i<8;i++)
                {
                    x=cur_pair.first+dir[i][0];
                    y=cur_pair.second+dir[i][1];
                    if(x>n-1 || x<0 || y>n-1 || y<0)
                    continue;
                    if(grid[x][y]==0 && dist[x][y]>cur_weight+1)
                    {
                        dist[x][y]=cur_weight+1;
                        q.push({dist[x][y],make_pair(x,y)});
                    }
                    
                }
            // }
        }
        return -1;
    }
};
