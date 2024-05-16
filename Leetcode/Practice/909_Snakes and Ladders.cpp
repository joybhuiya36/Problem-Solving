class Solution {
public:
int r,c;
    vector<int> finder(int cur, int &n)
    {
        r=n-1-((cur-1)/n);
        if(n%2==r%2)
        c=n-1-((cur-1)%n);
        else c=((cur-1)%n);
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        int cur,t,step=0;
        vector<int> p;
        int visited[n][n];
        memset(visited,0,sizeof(visited));
        while(!q.empty())
        {
            t=q.size();
            while(t--)
            {
                cur=q.front();
                q.pop();
                if(cur==n*n) return step;
                for(int i=1;i<=6;i++)
                {
                    if(cur+i>n*n) break;
                    p=finder(cur+i,n);
                    if(visited[p[0]][p[1]]) continue;
                    visited[p[0]][p[1]]=1;
                    if(board[p[0]][p[1]]==-1)
                    q.push(cur+i);
                    else q.push(board[p[0]][p[1]]);
                }
            }
            step++;
        }
        return -1;
    }
};
