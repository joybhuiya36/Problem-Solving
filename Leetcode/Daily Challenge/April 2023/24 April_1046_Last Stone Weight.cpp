class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int cur,cur2;
        for(int i=0;i<stones.size();i++)
        pq.emplace(stones[i]);
        while(pq.size()>1)
        {
            cur=pq.top();
            pq.pop();
            cur2=pq.top();
            pq.pop();
            if(cur>cur2)
            {
                pq.push(cur-cur2);
            }
        }
        if(pq.size()==0)
        return 0;
        return pq.top();
    }
};
