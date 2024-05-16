class Solution {
public:
	int* getNSL(vector<int> &v, int n)
    {
        int *a=new int[n];
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
            a[i]=-1;
            else
            {
                while(!stk.empty() && v[stk.top()]>=v[i])
                {
                    stk.pop();
                }
                a[i]=stk.empty()? -1: stk.top();
            }
            stk.push(i);
        }
        return a;
    }
    int* getRSL(vector<int> &v, int n)
    {
        int *a=new int[n];
        stack<int> stk;
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            a[i]=n;
            else
        	{
                while(!stk.empty() && v[stk.top()]>v[i])
                {
                    stk.pop();
                }
                a[i]=stk.empty()? n: stk.top();
            }
            stk.push(i);
        }
        return a;
	}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int *NSL=getNSL(arr,n);
        int *RSL=getRSL(arr,n);

        long long sum=0,ns,rs,ways;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            ns=i-NSL[i];
            rs=RSL[i]-i;
            ways=ns*rs;
            sum+=ways*arr[i];
        }
        return sum%mod;
    }
};
