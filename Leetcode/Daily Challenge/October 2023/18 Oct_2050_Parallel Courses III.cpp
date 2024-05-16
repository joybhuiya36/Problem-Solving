class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rlt, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        int ind[n+1];
        memset(ind,0,sizeof(ind));
        for(int i=0;i<rlt.size();i++)
        {
            ind[rlt[i][1]]++;
            adj[rlt[i][0]].push_back(rlt[i][1]);
        }
        queue<int> q;
        int mxt[n+1];
        memset(mxt,0,sizeof(mxt));
        for(int i=1;i<=n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
                mxt[i]=time[i-1];
            }
        }
        int cur,j;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                j=adj[cur][i];
                if(--ind[j]==0)
                {
                    q.push(j);
                }
                mxt[j]=max(mxt[j], time[j-1]+mxt[cur]);
                //cout<<mxt[cur]<<" "<<time[j-1]<<endl;
            }
        }
        cur=0;
        for(int i=1;i<=n;i++)
        cur=max(cur,mxt[i]);
        return cur;
    }
};
