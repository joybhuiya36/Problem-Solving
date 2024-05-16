// C++
class Solution {
public:
int ans=INT_MAX,mx,n;
    void bkt(int idx, vector<int>& cookies, vector<int> &dist, int &k, int rem)
    {
        if(n-idx<rem)
        return;
        if(idx==n)
        {
            mx=-1;
            for(int i=0;i<k;i++)
            mx=max(mx,dist[i]);
            ans=min(mx,ans);
            return;
        }
        for(int i=0;i<k;i++)
        {
            rem-=dist[i]==0? 1:0;
            dist[i]+=cookies[idx];
            bkt(idx+1,cookies,dist,k,rem);
            dist[i]-=cookies[idx];
            rem+=dist[i]==0? 1:0;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int> dist(k,0);
        bkt(0,cookies,dist,k,k);
        return ans;
    }
};
// Python
class Solution:
    def __init__(self):
        self.n=0
        self.mx=-1
        self.ans=float('inf')
    def backtracking(self, idx: int, cookies: List[int], dist: List[int], k: int, rem: int):
        if self.n-idx<rem:
            return
        if idx==self.n:
            self.mx=-1
            for val in dist:
                self.mx=max(val,self.mx)
            self.ans=min(self.ans,self.mx)
            return
        for i in range(k):
            rem-= 1 if dist[i]==0 else 0
            dist[i]+=cookies[idx]
            self.backtracking(idx+1,cookies,dist,k,rem)
            dist[i]-=cookies[idx]
            rem+= 1 if dist[i]==0 else 0
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        dist=[0 for _ in range(k)]
        self.n=len(cookies)
        self.backtracking(0,cookies,dist,k,k)
        return self.ans
