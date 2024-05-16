//Heap
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
//Bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> v;
        int n=0;
        for(int &i:nums)
        {
            mp[i]++;
            n=max(n,mp[i]);
        }
        vector<vector<int>> bucket(n+1);
        for(auto &it:mp)
        {
            bucket[it.second].push_back(it.first);
        }
        for(int i=n;i>=0;i--)
        {
            for(auto &j:bucket[i])
            {
                v.push_back(j);
                if(v.size()==k)
                return v;
            }
        }
        return v;
    }
};
