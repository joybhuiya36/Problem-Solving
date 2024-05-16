class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int arr[n];
        arr[n-1]=s.back()=='1'?1:0;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='1')
            arr[i]=arr[i+1]+1;
            else arr[i]=arr[i+1];
        }
        int z=0, mx=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0') z++;
            mx=max(mx,z+arr[i+1]);
        }
        return mx;
    }
};
