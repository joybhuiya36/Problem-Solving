class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        int taken[26]={0};
        int lastIdx[26];
        for(int i=0;i<n;i++)
        lastIdx[s[i]-'a']=i;

        char c; int idx;
        string ans;
        for(int i=0;i<n;i++)
        {
            c=s[i];
            idx=s[i]-'a';
            if(taken[idx]) continue;
            while(ans.length()>0 && ans.back()>c && lastIdx[ans.back()-'a']>i)
            {
                taken[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(c);
            taken[idx]=1;
        }
        return ans;
    }
};
