class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int mx=arr[0], ap=1, cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]==arr[i])
            cnt++;
            else cnt=1;
            if(cnt>ap)
            {
                mx=arr[i];
                ap=cnt;
                if(ap>n/4) return mx;
            }
        }
        return mx;
    }
};
