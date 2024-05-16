class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int arr[26]={0};
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        n=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                n+=arr[i];
            }
        }
        return n;
    }
};
