class Solution {
public:
    long long putMarbles(vector<int>& wt, int k) {
        int n=wt.size()-1;
        if(!n) return 0;
        int arr[n];
        for(int i=0;i<n;i++)
        arr[i]=wt[i]+wt[i+1];
        sort(arr,arr+n);
        long long sum=0;
        for(int i=0;i<k-1;i++)
        sum+=arr[n-1-i]-arr[i];
        return sum;
    }
};
