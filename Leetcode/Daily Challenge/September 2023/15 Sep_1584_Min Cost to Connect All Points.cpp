class Solution {
public:
typedef pair<int,int> p;
    int minCostConnectPoints(vector<vector<int>>& pnt) {
        int n=pnt.size(),wt;
        vector<vector<p>> adj(n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                wt=abs(pnt[i][0]-pnt[j][0])+abs(pnt[i][1]-pnt[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        int sum=0;
        p cur;
        vector<bool> visit(n,false);
        while(!pq.empty())
        {
            cur=pq.top();
            pq.pop();
            if(visit[cur.second])
            continue;
            visit[cur.second]=true;
            sum+=cur.first;
            for(auto &v :adj[cur.second])
            {
                if(!visit[v.first])
                {
                    pq.push({v.second,v.first});
                }
            }
        }
        return sum;
    }
};
