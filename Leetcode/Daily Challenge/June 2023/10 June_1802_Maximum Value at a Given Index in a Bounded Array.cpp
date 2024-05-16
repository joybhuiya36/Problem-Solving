class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l=1,r=maxSum,mid,left,right,sum;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            sum=(mid*(mid-1))/2;
            left=mid-1-index;
            if(left>0)
            left=sum-((left*(left+1))/2);
            else left=sum+abs(left);
            right=mid-1-(n-1-index);
            if(right>0)
            right=sum-((right*(right+1))/2);
            else right=sum+abs(right);
            sum=left+mid+right;
            if(sum>maxSum)
            r=mid-1;
            else l=mid+1;
        }
        return r;
    }
};
//Test Case
//4
//2
//6
//6
//1
//10
//40
//27
//600
//40000
//2702
//60000
//4
//2
//4
