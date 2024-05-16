class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        int alph[26]={0};
        for(int i=0;i<n;i++)
        alph[s[i]-'a']++;
        vector<int> v;
        int mx=0;
        for(int i=0;i<26;i++)
        {
            if(alph[i]>0)
            v.push_back(alph[i]);
            mx=max(mx,alph[i]);
        }
        sort(v.begin(),v.end());
        int c=0;
        int a[mx+1];
        memset(a,0,sizeof(a));
        for(int i=0;i<v.size();i++)
        a[v[i]]=1;
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i]==v[i+1])
            {
                n=v[i];
                while(n>0 && a[n]==1)
                {
                    c++;
                    n--;
                }
                if(n>0)
                a[n]=1;
            }
        }
        return c;
    }
};
