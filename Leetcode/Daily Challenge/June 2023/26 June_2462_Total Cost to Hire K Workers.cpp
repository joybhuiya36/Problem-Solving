class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long total=0;
        int n=costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int l=cand-1,r=n;
        for(int i=0;i<cand;i++)
        pq.push({costs[i],i});
        for(int i=n-1;i>=n-cand;i--)
        {
            if(l<r-1)
            {
                pq.push({costs[i],i});
                r--;
            }
        }
        for(int i=0;i<k;i++)
        {
            pair<int,int> cur=pq.top();
            total+=cur.first;
            pq.pop();
            if(r-l>1)
            {
                if(cur.second<=l)
                {
                    l++;
                    pq.push({costs[l],l});
                }
                else
                {
                    r--;
                    pq.push({costs[r],r});
                }
            }
        }
        return total;
    }
};
