// if n=21, k=17, maxPts=10, then P(17)=P(16)*P(1), here P(1-maxPts) is constant, i.e. (1/maxPts)
// in k==0 basecase, P(0)=1.00
//P(14)=P(13)+P(12)+P(11)+....+P(3)
//P(15)=P(14)+P(13)+P(12)+....+P(4)
//P(16)=P(15)+P(14)+P(13)+....+P(5)
//as k=17
//P(17)=P(16)+P(15)+P(14)+....+P(6)
//P(18)=P(16)+P(15)+P(14)+....+P(7), here P(18)=P(16)*P(1)+P(15)*P(2)+....+P(7)*P(10), multiply by constant
//By Sliding Windows Approach
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts) return 1;
        double dp[n+1];
        dp[0]=1.0;
        double sum=1.0, ans=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=sum/maxPts;
            if(i<k)
            sum+=dp[i];
            if(i-maxPts>=0)
            sum-=dp[i-maxPts];
            if(i>=k)
            ans+=dp[i]; //summing upto n, i.e. k-n propabilities
        }
        return ans;
    }
};
