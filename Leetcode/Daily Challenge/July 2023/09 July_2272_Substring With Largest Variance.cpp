class Solution {
public:
    int largestVariance(string s) {
        int n=s.length(),f1,f2,ans=0;
        int mp[26]={0};
        bool pre2nd;
        char ch;
        for(int i=0;i<n;i++)
        mp[s[i]-'a']=1;
        for(char i='a';i<='z';i++)
        {
            for(char j='a';j<='z';j++)
            {
                if(!mp[i-'a'] || !mp[j-'a'] || i==j)
                continue;
                f1=0; f2=0; pre2nd=false;
                for(int k=0;k<n;k++)
                {
                    ch=s[k];
                    if(ch==i)
                    f1++;
                    if(ch==j)
                    f2++;
                    if(f2>0)
                    ans=max(ans,f1-f2);
                    else
                    {
                        if(pre2nd==true)
                        ans=max(ans,f1-1);
                    }
                    if(f1<f2)
                    {
                        f1=0; f2=0; pre2nd=true;
                    }
                }
            }
        }
        return ans;
    }
};
