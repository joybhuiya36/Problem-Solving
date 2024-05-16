class Solution {
public:
    int partitionString(string s) {
        int arr[26]={0};
        int count=1;
        for(char &c:s)
        {
            if(arr[c-'a']>0)
            {
                count++;
                for(int i=0;i<26;i++)
                arr[i]=0;
                arr[c-'a']++;
            }
            else arr[c-'a']++;
        }
        return count;
    }
};
