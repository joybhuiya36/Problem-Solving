class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if(w1.length()!=w2.length())
        return false;
        int a[26]={0};
        int b[26]={0};
        int n=w1.length();
        for(int i=0;i<n;i++)
        {
            a[w1[i]-'a']++;
            b[w2[i]-'a']++;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<26;i++)
        {
            if(a[i]>0)
            {
                if(b[i]==0)
                return false;
                mp[a[i]]++;
            }
            else
            {
                if(b[i]>0)
                return false;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(b[i]>0)
            {
                n=--mp[b[i]];
                if(n<0)
                return false;
            }
        }
        return true;
    }
};
