class Solution {
public:
    int longestPalindrome(string s) {
        int arr[128];
        for(int i=65;i<128;i++)
        arr[i]=0;
        for(char &c:s)
        arr[int(c)]++;
        int len=0, flag=0;
        for(int i=65;i<128;i++)
        {
            len+=(arr[i]/2)*2;
            if(flag==0 && arr[i]%2==1)
            {
                len++;
                flag=1;
            }
        }
        return len;
    }
};
