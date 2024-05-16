//Python
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
