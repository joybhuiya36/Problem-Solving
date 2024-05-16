class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> v;
        for(int &i:nums)
        mp[i]++;
        for(auto &it:mp)
        {
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k)
            pq.pop();
        }
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
