class Solution {
public:
typedef pair<int,int> p;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<p> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({profits[i],capital[i]});
        }
        sort(v.begin(),v.end(),[&](p a, p b){
            return a.second<b.second;
        });
        priority_queue<int> pq;
        int i=0;
        while(k--)
        {
            while(i<n && w>=v[i].second)
            {
                pq.push(v[i].first);
                i++;
            }
            if(!pq.empty())
            {
            	w+=pq.top();
            	pq.pop();
            }
        }
        return w;
    }
};
