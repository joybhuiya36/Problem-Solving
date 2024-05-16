//Brute Force Optimal
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(), n=nums2.size();
        priority_queue<vector<int>> pq;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pq.size()==k && nums1[i]+nums2[j]>pq.top()[0])
                break;
                pq.push({nums1[i]+nums2[j],nums1[i],nums2[j]});
                if(pq.size()>k)
                pq.pop();
            }
        }
        vector<vector<int>> v;
        while(!pq.empty())
        {
            v.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return v;
    }
};
//Optimized
class Solution {
public:
typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p,vector<p>,greater<p>> pq;
        set<pair<int,int>> visited;
        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        vector<vector<int>> v;
        int m=nums1.size(), n=nums2.size(), i, j;
        p cur;
        while(k-- && !pq.empty())
        {
            cur=pq.top();
            pq.pop();
            i=cur.second.first; j=cur.second.second;
            v.push_back({nums1[i],nums2[j]});
            if(i+1<m && !visited.count({i+1,j}))
            {
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if(j+1<n && !visited.count({i,j+1}))
            {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return v;
    }
};
