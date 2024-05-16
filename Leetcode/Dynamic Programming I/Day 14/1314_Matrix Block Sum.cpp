//Python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m=len(mat)
        n=len(mat[0])
        sum=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1,1):
            for j in range(1,n+1,1):
                sum[i][j]=mat[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
        x1=0
        y1=0
        x2=0
        y2=0
        for i in range(m):
            if i-k>=0: x1=i-k
            else: x1=0
            if i+k<m: x2=i+k
            else: x2=m-1
            for j in range(n):
                if j-k>=0: y1=j-k
                else: y1=0
                if j+k<n: y2=j+k
                else: y2=n-1
                mat[i][j]=sum[x2+1][y2+1]-sum[x1][y2+1]-sum[x2+1][y1]+sum[x1][y1]
        return mat
