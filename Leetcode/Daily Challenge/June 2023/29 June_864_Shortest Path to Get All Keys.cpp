class Solution {
public:
int m,n;
    bool inline isSafe(int &i, int &j, vector<string> &grid)
    {
        return i>=0 && i<m && j>=0 && j<n && grid[i][j]!='#';
    }
    bool hasKey(int &key, char &ch)
    {
        return (key>>(ch-'A'))&1;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        m=grid.size(), n=grid[0].size();
        int keys=0;
        pair<int,int> start;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>='a' && grid[i][j]<='f')  // 6 keys maximum
                keys++;
                else if(grid[i][j]=='@')
                start={i,j};
            }
        }
        if(keys==0) return 0;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int final_keys_status=pow(2,keys)-1;
        int visit[m][n][final_keys_status+1];
        memset(visit,0,sizeof(visit));
        queue<vector<int>> q;
        q.push({start.first,start.second,0,0});    // {i,j,steps,keys_status}
        vector<int> cur;
        int x,y,ii,jj,steps,cur_status;
        char ch;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            ii=cur[0];
            jj=cur[1];
            steps=cur[2];
            cur_status=cur[3];
            if(final_keys_status==cur_status)
            return steps;
            for(int i=0;i<4;i++)
            {
                x=dir[i][0]+ii;
                y=dir[i][1]+jj;
                
                if(isSafe(x,y,grid))
                {
                    ch=grid[x][y];
                    
                    if(ch>='a' && ch<='f') // Keys a-f
                    {
                        int new_keys_status=(cur_status|(1<<(ch-'a')));
                        if(visit[x][y][new_keys_status]==0)
                        {
                            visit[x][y][new_keys_status]=1;
                            q.push({x,y,steps+1,new_keys_status});
                        }
                    }
                    else if(ch>='A' && ch<='F')    // Locks A-F
                    {
                        if(visit[x][y][cur_status]==0 && hasKey(cur_status,ch))
                        {
                            visit[x][y][cur_status]=1;
                            q.push({x,y,steps+1,cur_status});
                        }
                    }
                    else  // white space . or @
                    {
                        if(visit[x][y][cur_status]==0)
                        {
                            visit[x][y][cur_status]=1;
                            q.push({x,y,steps+1,cur_status});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
