class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=1;
        arr[0]=1;
        while(i<n)
        {
            if(arr[i]-arr[i-1]>1)
            {
                arr[i]=arr[i-1]+1;
            }
            i++;
        }
        return arr[n-1];
    }
};
