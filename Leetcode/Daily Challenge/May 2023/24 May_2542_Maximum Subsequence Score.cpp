//Heap
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        priority_queue<pair<int,int>> pq;
        priority_queue<int,vector<int>,greater<int>> q;

        for(int i=0;i<n;i++)
        pq.push({nums2[i],nums1[i]});

        int mn,val;
        long long sum=0,total=-1;
        while(!pq.empty())
        {
            mn=pq.top().first;
            val=pq.top().second;
            pq.pop();
            sum+=val;
            q.push(val);
            if(q.size()>k)
            {
                sum-=q.top();
                q.pop();
            }
            if(q.size()==k)
            total=max(total,sum*mn);
        }
        return total;
    }
};
//Recursion Brute Force (TLE)
class Solution {
public:
    int score(int idx, int sum, int mn, vector<int> &n1, vector<int> &n2, int k, int &n)
    {
        if(k==0)
        return sum*mn;
        if(idx==n)
        return -1e9;
        int not_taken=score(idx+1,sum,mn,n1,n2,k,n);
        int taken=score(idx+1,sum+n1[idx],min(mn,n2[idx]),n1,n2,k-1,n);
        return max(taken,not_taken);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        return score(0,0,1e9,nums1,nums2,k,n);
    }
};
