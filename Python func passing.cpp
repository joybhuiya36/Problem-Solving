class Solution:
    def __init__(self):
        self.n=0
        self.mx=-1
        self.ans=float('inf')
    def backtracking(self, idx: int, cookies: List[int], dist: List[int], k: int):
        if idx==self.n:
            self.mx=-1
            for val in dist:
                self.mx=max(val,self.mx)
            self.ans=min(self.ans,self.mx)
            return
        for i in range(k):
            dist[i]+=cookies[idx]
            self.backtracking(idx+1,cookies,dist,k)
            dist[i]-=cookies[idx]
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        dist=[0 for _ in range(k)]
        self.n=len(cookies)
        self.backtracking(0,cookies,dist,k)
        return self.ans
        
class Solution:
    def maximumRequests(self, n: int, rqst: List[List[int]]) -> int:
        m=len(rqst)
        rslt=[0 for _ in range(n)]
        global ans
        ans=-1
        def bkt(idx,rqst,rslt,m,count):
            if idx==m:
                for i in rslt:
                    if i!=0:
                        return
                global ans
                ans=max(ans,count)
                return
            rslt[rqst[idx][0]]-=1
            rslt[rqst[idx][1]]+=1
            bkt(idx+1,rqst,rslt,m,count+1)  #taken
            rslt[rqst[idx][0]]+=1
            rslt[rqst[idx][1]]-=1
            bkt(idx+1,rqst,rslt,m,count)  #not_taken
        bkt(0,rqst,rslt,m,0)
        return ans

