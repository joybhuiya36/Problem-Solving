class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int f[26];
        int l[26];
        memset(f,-1,sizeof(f));
        memset(l,-1,sizeof(l));
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(f[s[i]-'a']==-1)
            f[s[i]-'a']=i;
            l[s[i]-'a']=i;
        }
        n=-1;
        for(int i=0;i<26;i++)
        {
            n=max(n,l[i]-f[i]-1);
        }
        return n;
    }
};
